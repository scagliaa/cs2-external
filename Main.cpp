#include "Features/Features.h"
#include <iostream>
int main()
{
	SetConsoleTitle(L"CS2-external");
	g_process_handler.init();
	
	while (!Offsets::dwClient)
		Offsets::dwClient = utils::get_module_address(L"client.dll");

	while (!Offsets::dwEngine)
		Offsets::dwEngine = utils::get_module_address(L"engine.dll");

	printf("Found client: 0x%p\n", &Offsets::dwClient);
	printf("Found engine: 0x%p\n", &Offsets::dwEngine);
	
	while (!GetAsyncKeyState(VK_F11))
	{
		printf("Filling entity cache.");

		g_entity_cache.fill();		
		{
			bunnyhop::run();
		}

		printf("Clearing entity cache..");
		g_entity_cache.clear();
	}

	printf("Freeing process..");
	g_process_handler.free();
	
	return 0;
}