#pragma once
#include "../Defines.h"

class vector;

class c_entity
{
	DWORD m_eThis;
public:
	explicit operator bool() const;
	c_entity(const DWORD&dw_address);
	auto get_this() const -> DWORD;
	auto get_flags() const -> int;
	auto get_health() const -> int;
	auto get_armor() const -> int;
	auto get_team_num() const -> int;
	[[nodiscard]] unsigned char get_life_state() const;
	auto is_alive() const -> bool;
	auto is_on_ground() const -> bool;
	auto get_origin() const -> vector;
};
