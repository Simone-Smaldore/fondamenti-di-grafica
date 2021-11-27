#pragma once

#include <vector>
#include <cstdio>
#include <iostream>
#include "aabb.h"
#include "ray.h"
#include "Object.h"
#define TINYOBJLOADER_IMPLEMENTATION
#include "tiny_obj_loader.h"

using namespace std;

class mesh : public Object {
public:

	vector<point3d> vertices;				// mesh vertices 
	vector<vec3> normals;				// average normal at each vertex;
	vector<vector<int> > vertex_faces;		// the triangles shared by each vertex
	int num_vertices; 										// number of vertices
	int num_normals;
	int num_shapes;
	int num_faces;
	aabb aabb_mesh;

	bool areNormals = false;

	mesh(const char* filename, const char* basepath = NULL, bool triangulate = true) {
		load_mesh(filename, basepath, triangulate);
	};

	bool load_mesh(const char* filename, const char* basepath, bool triangulate);

	virtual bool hit_object(const ray& r, float tmin, float tmax, hit_record& rec);
	virtual bool hit_shadow(const ray& r, float t_min, float t_max);

//private:
//	vector<vector<int>> findBlocksTouched(const ray& r, point3d& hit_point);
};


bool mesh::load_mesh(const char* filename, const char* basepath = NULL, bool triangulate = true)
{
	tinyobj::attrib_t attrib;
	std::vector<tinyobj::shape_t> shapes;
	std::vector<tinyobj::material_t> materials;

	std::string err;
	std::string war;
	bool ret = tinyobj::LoadObj(&attrib, &shapes, &materials, &war, &err, filename, basepath, triangulate);

	if (!err.empty()) {
		std::cerr << err << std::endl;
		return false;
	}

	if (!ret) {
		printf("Failed to load/parse .obj.\n");
		return false;
	}

	num_vertices = (attrib.vertices.size() / 3);
	num_normals = (attrib.normals.size() / 3);
	num_shapes = shapes.size();

	aabb_mesh.pmax = point3d(FLT_MIN, FLT_MIN, FLT_MIN);
	aabb_mesh.pmin = point3d(FLT_MAX, FLT_MAX, FLT_MAX);

	for (int v = 0; v < attrib.vertices.size() / 3; v++) {
		point3d p = point3d(attrib.vertices[3 * v + 0], attrib.vertices[3 * v + 1], attrib.vertices[3 * v + 2]);

		aabb_mesh.pmin.x = ffmin(p.x, aabb_mesh.pmin.x);
		aabb_mesh.pmin.y = ffmin(p.y, aabb_mesh.pmin.y);
		aabb_mesh.pmin.z = ffmin(p.z, aabb_mesh.pmin.z);
		aabb_mesh.pmax.x = ffmax(p.x, aabb_mesh.pmax.x);
		aabb_mesh.pmax.y = ffmax(p.y, aabb_mesh.pmax.y);
		aabb_mesh.pmax.z = ffmax(p.z, aabb_mesh.pmax.z);

		vertices.push_back(p);
		//vertices[v] = p;
	}

	if (attrib.normals.size() > 0)
	{
		areNormals = true;
		for (int v = 0; v < attrib.normals.size() / 3; v++) {
			normals.push_back(vec3(attrib.normals[3 * v + 0], attrib.normals[3 * v + 1], attrib.normals[3 * v + 2]));
			//normals[v] = vector3D(attrib.normals[3 * v + 0], attrib.normals[3 * v + 1], attrib.normals[3 * v + 2]);
		}
	}

	vertex_faces.push_back(vector<int>());
	vertex_faces.push_back(vector<int>());
	vertex_faces.push_back(vector<int>());

	num_faces = 0;
	// For each shape
	for (int s = 0; s < shapes.size(); s++) {
		int index_offset = 0;

		// For each face
		for (int f = 0; f < shapes[s].mesh.num_face_vertices.size(); f++) {
			int fv = shapes[s].mesh.num_face_vertices[f];
			num_faces++;

			// For each vertex in the face
			for (int v = 0; v < fv; v++) {
				tinyobj::index_t idx = shapes[s].mesh.indices[index_offset + v];

				vertex_faces[0].push_back(idx.vertex_index);
				vertex_faces[1].push_back(idx.normal_index);
				vertex_faces[2].push_back(idx.texcoord_index);
			}

			index_offset += fv;
		}
	}

	cout << "MESH LOADED \n";
	cout << "NUM FACES: " << num_faces << endl;
	cout << "X_AABB MESH: {MIN: " << aabb_mesh.pmin.x << ", MAX: " << aabb_mesh.pmax.x << " }\n";
	cout << "Y_AABB MESH: {MIN: " << aabb_mesh.pmin.y << ", MAX: " << aabb_mesh.pmax.y << " }\n";
	cout << "Z_AABB MESH: {MIN: " << aabb_mesh.pmin.z << ", MAX: " << aabb_mesh.pmax.z << " }\n";

	return true;
}


bool triangle_intersection(const ray& r, float tmin, float tmax, hit_record& rec, const point3d& v0, const point3d& v1, const point3d& v2, float& u, float& v)
{
	const float EPSILON = 0.0000001f;
	vec3 edge1, edge2, h, s, q;
	float a, f;	// , u, v;
	edge1 = v1 - v0;
	edge2 = v2 - v0;
	h = cross(r.d, edge2);
	a = dot(edge1, h);
	if (a > -EPSILON && a < EPSILON)
		return false;
	f = 1 / a;
	s = r.o - v0;
	u = f * (dot(s, h));
	if (u < 0.0f || u > 1.0f)
		return false;
	q = cross(s, edge1);
	v = f * dot(r.d, q);
	if (v < 0.0f || u + v > 1.0f)
		return false;
	// At this stage we can compute t to find out where the intersection point is on the line.
	float t = f * dot(edge2, q);
	if (t > tmin && t < tmax) {
		if (t > EPSILON) // ray intersection
		{
			rec.normal = normalize(cross(v1 - v0, v2 - v0));
			rec.t = dot((v0 - r.o), rec.normal) / dot(r.direction(), rec.normal);
			rec.p = r.point_at_parameter(rec.t);
			return true;
		}
	}
	// This means that there is a line intersection but not a ray intersection.
	return false;
}


bool mesh::hit_object(const ray& ray, float t_min, float t_max, hit_record& rec) {
	bool hit_anything = false;
	hit_record temp_rec;
	point3d hit_point = point3d(0,0,0);
	float closest_so_far = t_max;
	float u, v;

	if (aabb_mesh.hit(ray, t_min, t_max, hit_point) == false)
		return false;

	//vector<vector<int>> blocks_touched = findBlocksTouched(ray, hit_point);

	for (int i = 0; i < num_faces; i++)
	{
		int i0 = vertex_faces[0][3 * i + 0];
		int i1 = vertex_faces[0][3 * i + 1];
		int i2 = vertex_faces[0][3 * i + 2];

		point3d v0 = vertices[i0];
		point3d v1 = vertices[i1];
		point3d v2 = vertices[i2];

		if (triangle_intersection(ray, t_min, closest_so_far, temp_rec, v0, v1, v2, u, v)) {
			hit_anything = true;
			closest_so_far = temp_rec.t;
			rec = temp_rec;

			if (areNormals)
			{
				i0 = vertex_faces[1][3 * i + 0];
				i1 = vertex_faces[1][3 * i + 1];
				i2 = vertex_faces[1][3 * i + 2];
				vec3 bary(1.0f - u - v, u, v);
				rec.normal = normalize(normals[i0] * bary.x + normals[i1] * bary.y + normals[i2] * bary.z);
			}
		}
	}
	return hit_anything;
}

bool mesh::hit_shadow(const ray& r, float t_min, float t_max) {
	return false;
}

//vector<vector<int>> mesh::findBlocksTouched(const ray& r, point3d& hit_point) {
//	vector<vector<int>> listBlocks;
//
//	float stepX = (aabb_mesh.pmax.x - aabb_mesh.pmin.x) / 10;
//	float stepY = (aabb_mesh.pmax.y - aabb_mesh.pmin.y) / 10;
//	float stepZ = (aabb_mesh.pmax.z - aabb_mesh.pmin.z) / 10;
//
//	int firstX = floor((hit_point.x - aabb_mesh.pmin.x) / stepX);
//	int firstY = floor((hit_point.y - aabb_mesh.pmin.y) / stepX);
//	int firstZ = floor((hit_point.z - aabb_mesh.pmin.z) / stepX);
//
//	listBlocks.push_back(vector<int>(3));
//	listBlocks[listBlocks.size() - 1][0] = firstX;
//	listBlocks[listBlocks.size() - 1][1] = firstY;
//	listBlocks[listBlocks.size() - 1][2] = firstZ;
//
//	float nextX = (firstX + 1) * stepX;
//	float nextY = (firstY + 1) * stepY;
//	float nextZ = (firstZ + 1) * stepZ;
//
//	float l = r.d.x;
//	float m = r.d.y;
//	float n = r.d.z;
//
//	point3d nextXPass = point3d(nextX, (nextX - firstX) * m / l - firstY, (nextX - firstX) * n / l - firstZ);
//	point3d nextYPass = point3d((nextY - firstY) * l / m - firstX, nextY, (nextY - firstY) * n / m - firstZ);
//	point3d nextZPass = point3d((nextZ - firstZ) * l / n - firstX, (nextZ - firstZ) * m / n - firstY, nextZ);
//
//	float nextTx = r.t_at_point(nextXPass);
//	float nextTy = r.t_at_point(nextYPass);
//	float nextTz = r.t_at_point(nextZPass);
//
//	if (nextTx < nextTy) {
//		if (nextTx < nextTz) {
//
//		}
//		else {
//
//		}
//	}
//	else {
//		if (nextTy < nextTz) {
//
//		}
//		else {
//
//		}
//	}
//
//
//	return listBlocks;
//}
