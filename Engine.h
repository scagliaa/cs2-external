#pragma once
#include "../Defines.h"

#include "../../../Utils/Math/Vector.h"


class c_engine
{
public:
	static auto get_view_angles() -> vector;
	static auto set_view_angles(vector& v_angles, const bool clamp = true) -> void;
};

inline c_engine g_engine;