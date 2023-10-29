#pragma once
#pragma warning (push)
#pragma warning (disable : 26451)
#pragma warning (disable : 26495)
#pragma warning (disable : 26451)
#pragma warning (disable : 4244)

#include "Vector.h"
#include <cmath>

namespace math
{
	inline void sin_cos(float radians, float *sine, float *cosine)
	{
		_asm
		{
			fld		DWORD PTR[radians]
			fsincos

			mov edx, DWORD PTR[cosine]
			mov eax, DWORD PTR[sine]

			fstp DWORD PTR[edx]
			fstp DWORD PTR[eax]
		}
	}

	inline double __declspec (naked) __fastcall fast_sqrt(double n)
	{
		_asm fld qword ptr[esp + 4]
			_asm fsqrt
		_asm ret 8
	}

	inline void angle_vectors(const vector &angles, vector *forward, vector *right = nullptr, vector *up = nullptr)
	{
		float sr;
		float sp;
		float sy;
		float cr;
		float cp;
		float cy;
		sin_cos(DEG2_RAD(angles.x), &sp, &cp);
		sin_cos(DEG2_RAD(angles.y), &sy, &cy);
		sin_cos(DEG2_RAD(angles.z), &sr, &cr);

		if (forward)
		{
			forward->x = cp * cy;
			forward->y = cp * sy;
			forward->z = -sp;
		}

		if (right)
		{
			right->x = (-1 * sr * sp * cy + -1 * cr * -sy);
			right->y = (-1 * sr * sp * sy + -1 * cr * cy);
			right->z = -1 * sr * cp;
		}

		if (up)
		{
			up->x = (cr * sp * cy + -sr * -sy);
			up->y = (cr * sp * sy + -sr * cy);
			up->z = cr * cp;
		}
	}

	inline float normalize_angle(float ang)
	{
		if (!std::isfinite(ang))
		{
			return 0.0F;
		}

		return std::remainder(ang, 360.0F);
	}


	inline void clamp_angles(vector& v)
	{
		v.x = std::clamp(v.x, -89.0f, 89.0f);
		v.y = normalize_angle(v.y);
		v.z = 0.0f;
	}

	inline vector calc_angle(const vector &source, const vector &destination)
	{
		auto angles = vector(0.0f, 0.0f, 0.0f);
		const vector delta = (source - destination);
		const float f_hyp = fast_sqrt((delta.x * delta.x) + (delta.y * delta.y));

		angles.x = atanf(delta.z / f_hyp) * M_RADPI;
		angles.y = atanf(delta.y / delta.x) * M_RADPI;
		angles.z = 0.0F;

		if (delta.x >= 0.0F)
			angles.y += 180.0F;

		return angles;
	}

	inline float calc_fov(const vector &src, const vector &dst)
	{
		auto v_src = vector();
		angle_vectors(src, &v_src);

		auto v_dst = vector();
		angle_vectors(dst, &v_dst);

		float result = RAD_2DEG(acos(v_dst.dot(v_src) / v_dst.length_sqrt()));

		if (!isfinite(result) || isinf(result) || isnan(result))
			result = 0.0F;

		return result;
	}
}

#pragma warning (pop)