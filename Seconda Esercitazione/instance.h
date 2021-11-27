#pragma once
#include "Object.h"
#include "utilitySDLInline.h"
#include "material.h"
#include "matrix4D.h"

class instance : public Object{

public:
		instance(Object* nobj_ptr, material* m) {
			object_ptr = nobj_ptr;
			mat = m;
		}

		instance* clone(void) const;

		virtual bool hit_object(const ray& r, float t_min, float t_max, hit_record& rec)override;

		virtual bool hit_shadow(const ray& r, float t_min, float t_max) override;

		void identity();

		void translate(const vec3& trans);
		void translate(const float dx, const float dy, const float dz);
		void scale(const vec3& s);
		void scale(const float a, const float b, const float c);
		void rotate_x(const float r);
		void rotate_y(const float r);
		void rotate_z(const float r);

		void setMaterial(material* m) {
			mat = m;
		}
		material* getMaterial() {
			return(mat);
		}

	private:
		Object* object_ptr; 
		matrix4D inverse_matrix; 
		matrix4D current_matrix; 
		material* mat; 
};



