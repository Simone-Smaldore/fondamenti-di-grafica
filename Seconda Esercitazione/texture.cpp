#include "texture.h"

color image_texture::value(float u, float v, const point3d& p) const {
	int i = (u) * float(imageWidth);
	int j = (1.0f - v) * imageHeight - 0.001f;
	if (i < 0) i = 0;
	if (j < 0) j = 0;
	if (i > imageWidth - 1) i = imageWidth - 1;
	if (j > imageHeight - 1) j = imageHeight - 1;

	Uint32 value = getpixel(surface, i, j);

	float red = float((value >> 16) & 0xff) / 255.0f;
	float green = float((value >> 8) & 0xff) / 255.0f;
	float blue = float(value & 0xff) / 255.0f;

	return color(blue, green, red);
}