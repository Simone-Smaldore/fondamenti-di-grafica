#include "instance.h"
#include <cmath>

instance* instance::clone(void) const {
	return (new instance(*this));
}
void instance::identity() {
	set_identity(current_matrix);
	set_identity(inverse_matrix);
}

void instance::translate(const float dx, const float dy, const float dz) {
	matrix4D inv_translation_matrix; 
	inv_translation_matrix.m[0][3] = -dx;
	inv_translation_matrix.m[1][3] = -dy;
	inv_translation_matrix.m[2][3] = -dz;
	inverse_matrix = inverse_matrix * inv_translation_matrix;
	matrix4D translation_matrix; 
	translation_matrix.m[0][3] = dx;
	translation_matrix.m[1][3] = dy;
	translation_matrix.m[2][3] = dz;
	current_matrix = translation_matrix * current_matrix;
}

void instance::translate(const vec3& trans) {
	matrix4D inv_translation_matrix;
	inv_translation_matrix.m[0][3] = -trans.x;
	inv_translation_matrix.m[1][3] = -trans.y;
	inv_translation_matrix.m[2][3] = -trans.z;
	inverse_matrix = inverse_matrix * inv_translation_matrix;
	matrix4D translation_matrix;
	translation_matrix.m[0][3] = trans.x;
	translation_matrix.m[1][3] = trans.y;
	translation_matrix.m[2][3] = trans.z;
	current_matrix = translation_matrix * current_matrix;
}

void instance::scale(const float a, const float b, const float c) {
	matrix4D inv_scaling_matrix; 
	inv_scaling_matrix.m[0][0] = 1.0f / a;
	inv_scaling_matrix.m[1][1] = 1.0f / b;
	inv_scaling_matrix.m[2][2] = 1.0f / c;
	inverse_matrix = inverse_matrix * inv_scaling_matrix;
	matrix4D scaling_matrix;
	scaling_matrix.m[0][0] = a;
	scaling_matrix.m[1][1] = b;
	scaling_matrix.m[2][2] = c;
	current_matrix = scaling_matrix * current_matrix;
}

void instance::scale(const vec3& s) {
	matrix4D inv_scaling_matrix;
	inv_scaling_matrix.m[0][0] = 1.0f / s.x;
	inv_scaling_matrix.m[1][1] = 1.0f / s.y;
	inv_scaling_matrix.m[2][2] = 1.0f / s.z;
	inverse_matrix = inverse_matrix * inv_scaling_matrix;
	matrix4D scaling_matrix;
	scaling_matrix.m[0][0] = s.x;
	scaling_matrix.m[1][1] = s.y;
	scaling_matrix.m[2][2] = s.z;
	current_matrix = scaling_matrix * current_matrix;
}

void instance::rotate_x(const float theta) {
	float sin_theta = sin(deg2rad(theta));
	float cos_theta = cos(deg2rad(theta));
	matrix4D inv_x_rotation_matrix;
	inv_x_rotation_matrix.m[1][1] = inv_x_rotation_matrix.m[2][2] = cos_theta;
	inv_x_rotation_matrix.m[1][2] = sin_theta;
	inv_x_rotation_matrix.m[2][1] = -sin_theta;
	inverse_matrix = inverse_matrix * inv_x_rotation_matrix;
	matrix4D x_rotation_matrix; 
	x_rotation_matrix.m[1][1] = x_rotation_matrix.m[2][2] = cos_theta;
	x_rotation_matrix.m[1][2] = -sin_theta;
	x_rotation_matrix.m[2][1] = sin_theta;
	current_matrix = x_rotation_matrix * current_matrix;
}


void instance::rotate_y(const float theta) {
	float sin_theta = sin(deg2rad(theta));
	float cos_theta = cos(deg2rad(theta));
	matrix4D inv_y_rotation_matrix;					
	inv_y_rotation_matrix.m[0][0] = cos_theta;
	inv_y_rotation_matrix.m[0][2] = -sin_theta;
	inv_y_rotation_matrix.m[2][0] = sin_theta;
	inv_y_rotation_matrix.m[2][2] = cos_theta;
	inverse_matrix = inverse_matrix * inv_y_rotation_matrix;
	matrix4D y_rotation_matrix;					
	y_rotation_matrix.m[0][0] = cos_theta;
	y_rotation_matrix.m[0][2] = sin_theta;
	y_rotation_matrix.m[2][0] = -sin_theta;
	y_rotation_matrix.m[2][2] = cos_theta;
	current_matrix = current_matrix * y_rotation_matrix;
}

void instance::rotate_z(const float theta) {
	float sin_theta = sin(deg2rad(theta));
	float cos_theta = cos(deg2rad(theta));
	matrix4D inv_z_rotation_matrix;					
	inv_z_rotation_matrix.m[0][0] = cos_theta;
	inv_z_rotation_matrix.m[0][1] = sin_theta;
	inv_z_rotation_matrix.m[1][0] = -sin_theta;
	inv_z_rotation_matrix.m[1][1] = cos_theta;
	inverse_matrix = inverse_matrix * inv_z_rotation_matrix;
	matrix4D z_rotation_matrix;						
	z_rotation_matrix.m[0][0] = cos_theta;
	z_rotation_matrix.m[0][1] = -sin_theta;
	z_rotation_matrix.m[1][0] = sin_theta;
	z_rotation_matrix.m[1][1] = cos_theta;
	current_matrix = z_rotation_matrix * current_matrix;
}



bool instance::hit_object(const ray& r, float t_min, float t_max, hit_record&rec) {
	ray inv_ray;
	inv_ray.o = inverse_matrix * r.o;
	inv_ray.d = inverse_matrix * r.d;
	if (object_ptr->hit_object(inv_ray, t_min, t_max, rec)) {
		rec.p = current_matrix * inv_ray.point_at_parameter(rec.t);
		rec.normal = normalize(transponse(inverse_matrix) * rec.normal);
		rec.m = *mat;
		return (true);
	}
	return (false);
}

bool instance::hit_shadow(const ray& r, float t_min, float t_max) {
	ray inv_ray;
	inv_ray.o = inverse_matrix * r.o;
	inv_ray.d = inverse_matrix * r.d;
	if (object_ptr->hit_shadow(inv_ray, t_min, t_max))
		return (true);
	return (false);
}

