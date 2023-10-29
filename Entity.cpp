#include "Entity.h"

c_entity::operator bool() const { return m_eThis != 0u; }

c_entity::c_entity(const DWORD& dw_address) { m_eThis = dw_address; }

auto c_entity::get_this() const -> DWORD { return m_eThis; }

auto c_entity::get_flags() const -> int { return utils::read<int>(m_eThis + Offsets::m_fFlags); }

auto c_entity::get_health() const -> int { return utils::read<int>(m_eThis + Offsets::m_pawnHealth); }

auto c_entity::get_armor() const -> int { return utils::read<int>(m_eThis + Offsets::m_pawnArmor); }

auto c_entity::get_team_num() const -> int { return utils::read<int>(m_eThis + Offsets::m_iTeamNum); }

auto c_entity::get_life_state() const -> byte { return utils::read<byte>(m_eThis + Offsets::m_lifeState); }

auto c_entity::is_alive() const -> bool { return get_life_state() == LIFE_ALIVE; }

auto c_entity::is_on_ground() const -> bool { return (get_flags() & FL_ONGROUND) != 0; }

auto c_entity::get_origin() const -> vector { return utils::read<vector>(reinterpret_cast<DWORD>(&m_eThis + Offsets::m_vecOrigin)); }