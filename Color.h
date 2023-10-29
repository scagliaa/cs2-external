#pragma once
#include "../Math/Vector.h"

using byte = unsigned char;
struct color_t { byte r = 0, g = 0, b = 0, a = 0; };

namespace color
{
	inline float tofloat(byte x) {
		return (static_cast<float>(x) / 255.0f);
	}

	inline vector tovec3(const color_t &x) {
		return {tofloat(x.r), tofloat(x.g), tofloat(x.b)};
	}

	inline unsigned long todword(const color_t &x) {
		return (x.r & 0xFF) << 24 | (x.g & 0xFF) << 16 | (x.b & 0xFF) << 8 | x.a & 0xFF;
	}
}