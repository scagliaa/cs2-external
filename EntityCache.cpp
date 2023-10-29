#include "EntityCache.h"
#include "../Client/Client.h"

void c_entity_cache::fill()
{
	const c_entity local = c_client::get_local_player();

	if (!local)
	{
		return;
	}

	m_local = local;

	for (auto n = 1; n < c_entity_list::get_highest_entity_index(); n++) 
	{
		c_entity entity = c_entity_list::get_entity(n);

		if (!entity)
		{
			continue;
		}

		switch (entity)
		{
			case local.get_team_num() != entity.get_team_num():
			{
				m_groups_[entity_group_type::PLAYERS_ENEMIES].push_back(entity);
				break;
			}

		default:
			m_groups_[entity_group_type::PLAYERS_TEAMMATES].push_back(entity);
				break;
		}
	}
}

void c_entity_cache::clear() {
	for (auto& snd : m_groups_ | std::views::values)
	{
		snd.clear();
	}
}

auto c_entity_cache::get_group(const entity_group_type group) -> const std::vector<c_entity>&
{
	return m_groups_[group];
}