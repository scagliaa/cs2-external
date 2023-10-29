#include "EntityList.h"

auto c_entity_list::get_highest_entity_index() -> int
{
	return 64;
}

auto c_entity_list::get_entity(const int n_index) -> DWORD
{
	return utils::read<DWORD>(Offsets::dwClient + Offsets::dwEntityList);
}
