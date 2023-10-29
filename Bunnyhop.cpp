#include "Bunnyhop.h"

void bunnyhop::run()
{
	if (const auto& local = g_entity_cache.m_local)
	{
		if ((GetAsyncKeyState(VK_SPACE) & 0x8000) != 0)
			c_client::set_jump(local.is_on_ground() ? 5 : 4);
	}
}