#pragma once
#include "../Defines.h"

class c_client
{
public:
	static auto get_local_player() -> DWORD;
	static auto get_entity_list() -> DWORD;
	static auto set_jump(const int n_to) -> DWORD;
};

inline c_client g_client;