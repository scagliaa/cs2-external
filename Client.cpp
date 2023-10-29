#include "Client.h"

auto c_client::get_local_player() -> DWORD { return Offsets::dwClient + Offsets::dwLocalPlayer; }
auto c_client::get_entity_list() -> DWORD { return Offsets::dwClient + Offsets::dwEntityList; }
auto c_client::set_jump(const int n) -> DWORD { return Offsets::dwClient + Offsets::dwJump; }
