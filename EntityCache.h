#pragma once
#include "../EntityList/EntityList.h"

enum struct entity_group_type
{
	PLAYERS_ALL, PLAYERS_ENEMIES, PLAYERS_TEAMMATES
};

class c_entity_cache
{
	std::map<entity_group_type, std::vector<c_entity>> m_groups_;
public:
	c_entity m_local = 0x0;
	void fill();
	void clear();
	auto get_group(entity_group_type group) -> const std::vector<c_entity>&;
};

inline c_entity_cache g_entity_cache;