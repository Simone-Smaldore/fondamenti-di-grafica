#pragma once
#include "vec3.h"
#include "point3d.h"

class matrix4D {

public:

	float	m[4][4];								// elements

	matrix4D(void) {
		m[0][0] = 1.0; m[0][1] = 0.0; m[0][2] = 0.0; m[0][3] = 0.0;
		m[1][0] = 0.0; m[1][1] = 1.0; m[1][2] = 0.0; m[1][3] = 0.0;
		m[2][0] = 0.0; m[2][1] = 0.0; m[2][2] = 1.0; m[2][3] = 0.0;
		m[3][0] = 0.0; m[3][1] = 0.0; m[3][2] = 0.0; m[3][3] = 1.0;
	}

	matrix4D(const matrix4D& mat);						// copy constructor

	~matrix4D(void) {}

	float& operator ()(int i, int j) {
		return (m[i][j]);
	}

	const float& operator ()(int i, int j) const {
		return (m[i][j]);
	}

	matrix4D& operator= (const matrix4D& rhs);

	matrix4D operator* (const matrix4D& mat) const;

	matrix4D operator/ (const float d);


	
};
void set_identity(matrix4D& mat);

matrix4D transponse(const matrix4D& mat);

vec3 operator* (const matrix4D& mat, const vec3& v);

point3d operator* (const matrix4D& mat, const point3d& p);




