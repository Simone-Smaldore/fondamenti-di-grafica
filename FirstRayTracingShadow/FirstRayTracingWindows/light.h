#pragma once

#include "utilitySDLInline.h"

class light {
	public:
		color ambient;
		color diffuse;
		color specular;

		float att_a;
		float att_b;
		float att_c;
};