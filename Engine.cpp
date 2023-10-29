#include "Engine.h"
#include "../../../Utils/Math/Math.h"

class vector;

auto c_engine::get_view_angles() -> vector
{
	return utils::read<vector>(Offsets::dwEngine + Offsets::dwViewAngles);
}

auto c_engine::set_view_angles(vector& v_angles, const bool clamp) -> void
{
	if (clamp)
	{
		math::clamp_angles(v_angles);
	}
	utils::write<vector>(Offsets::dwEngine + Offsets::dwViewAngles, v_angles);
}
