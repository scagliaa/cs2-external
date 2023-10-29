#pragma once
#include <math.h>

#define M_RADPI		57.295779513082
#define PI			3.14159265358979323846
#define FLT_EPSILON 1.192092896e-07F
#define DEG2_RAD(x)	((float)(x) * (float)((float)(PI) / 180.0f))
#define RAD_2DEG(x)	((float)(x) * (float)(180.0f / (float)(PI)))

class vector
{
public:
	float x, y, z;

	vector() { x = y = z = 0.0f; }

	void zero() {x = y = z = 0.f; }

	vector(float X, float Y, float Z) { x = X; y = Y; z = Z; }

	explicit vector(float *v) {x = v[0]; y = v[1]; z = v[2]; }

	explicit vector(const float *v) { x = v[0]; y = v[1]; z = v[2]; }

	vector(const vector &v) { x = v.x; y = v.y; z = v.z; }

	vector &operator=(const vector &v) = default;

	float &operator[](int i) { return reinterpret_cast<float*>(this)[i]; }

	float operator[](const int i) const
	{
		return ((float*)this)[i];
	}

	vector &operator+=(const vector &v) { x += v.x; y += v.y; z += v.z; return *this; }

	auto operator-=(const vector &v) -> vector& { x -= v.x; y -= v.y; z -= v.z; return *this; }

	vector &operator*=(const vector &v) { x *= v.x; y *= v.y; z *= v.z; return *this; }

	vector &operator/=(const vector &v) { x /= v.x; y /= v.y; z /= v.z; return *this; }

	vector &operator+=(float v) { x += v; y += v; z += v; return *this; }

	vector &operator-=(float v) { x -= v; y -= v; z -= v; return *this; }

	vector &operator*=(float v) { x *= v; y *= v; z *= v; return *this; }

	vector &operator/=(float v) { x /= v; y /= v; z /= v; return *this; }

	vector operator+(const vector &v) const { return {x + v.x, y + v.y, z + v.z};}

	vector operator-(const vector &v) const {return {x - v.x, y - v.y, z - v.z};}

	vector operator*(const vector &v) const { return {x * v.x, y * v.y, z * v.z};}

	vector operator/(const vector &v) const { return {x / v.x, y / v.y, z / v.z}; }

	vector operator+(float v) const { return {x + v, y + v, z + v}; }

	vector operator-(float v) const { return {x - v, y - v, z - v}; }

	vector operator*(float v) const { return {x * v, y * v, z * v}; }

	vector operator/(float v) const { return {x / v, y / v, z / v}; }

	void set(float X = 0.0f, float Y = 0.0f, float Z = 0.0f) { x = X; y = Y; z = Z; }

	[[nodiscard]] auto length() const -> float { return sqrtf(x * x + y * y + z * z); }

	[[nodiscard]] auto length_sqrt() const -> float { return (x * x + y * y + z * z); }

	float normalize()
	{
		const float fl_length = length();
		const float length = 1.f / (FLT_EPSILON + fl_length);

		x = x * length;
		y = y * length;
		z = z * length;

		return fl_length;
	}

	void rotate_2d(const float &fl_yaw)
	{
		const float r = DEG2_RAD(fl_yaw);
		const float s = sin(r);
		const float c = cos(r);

		const float _x = x;
		const float _y = y;

		x = (_x * c) - (_y * s);
		y = (_x * s) + (_y * c);
	}

	auto normalize_in_place() -> float
	{
		return normalize();
	}

	[[nodiscard]] float length_2df() const
	{
		return sqrtf(x * x + y * y);
	}

	[[nodiscard]] float length_2d_sqrt() const
	{
		return (x * x + y * y);
	}

	[[nodiscard]] float dist_to(const vector &v) const
	{
		return (*this - v).length();
	}

	[[nodiscard]] auto dist_to_sqr(const vector& v) const -> float
	{
		return (*this - v).length_sqrt();
	}

	auto dot(const vector& v) const -> float
	{
		return (x * v.x + y * v.y + z * v.z);
	}

	[[nodiscard]] vector cross(const vector &v) const
	{
		return {y * v.z - z * v.y, z * v.x - x * v.z, x * v.y - y * v.x};
	}

	[[nodiscard]] bool is_zero(void) const
	{
		return (x > -0.01f && x < 0.01f &&
			y > -0.01f && y < 0.01f &&
			z > -0.01f && z < 0.01f);
	}

	[[nodiscard]] vector Scale(float fl) const
	{
		return {x * fl, y * fl, z * fl};
	}

	void init(float ix, float iy, float iz)
	{
		x = ix; y = iy; z = iz;
	}
};