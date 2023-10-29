#pragma once
#include "../Entity/Entity.h"

class c_entity_list
{
public:
	[[nodiscard]] static int get_highest_entity_index();
	[[nodiscard]] static DWORD get_entity(int n_index);
};

inline c_entity_list g_entity_list;