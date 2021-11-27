#pragma once

#include "utilitySDLInline.h"
#include "utilityRayTracing.h"

using namespace std;

class texture {
public:
	virtual color value(float u, float v, const point3d& p) const = 0;
};

class constant_texture : public texture {
public:
	constant_texture() { }

	constant_texture(color c) : color(c) { }

	virtual color value(float u, float v, const point3d& p) const {
		return color;
	}

	color color;
};

class checker_texture : public texture {
public:
	checker_texture() { }

	checker_texture(texture* t0, texture* t1) : even(t0), odd(t1) { }

	virtual color value(float u, float v, const point3d& p) const {
		float sines = sin(2 * p.x) * sin(2 * p.y) * sin(2 * p.z);
		if (sines < 0)
			return odd->value(u, v, p);
		else
			return even->value(u, v, p);
	}

	texture* odd;
	texture* even;
};

class image_texture : public texture {
public:
	image_texture(const char* filename) {
		surface = loadTexture(filename, imageWidth, imageHeight);
	}

	virtual color value(float u, float v, const point3d& p) const;

	color* pixels;
	SDL_Surface* surface;
	int imageWidth, imageHeight;
};
