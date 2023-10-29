#pragma once
#include "../../Utils/Utils.h"

#define OFFSET(name, value) inline std::uintptr_t name = value

namespace Offsets
{
	OFFSET(dwClient, 0x0);
	OFFSET(dwEngine, 0x0);

	OFFSET(dwLocalPlayer, 0x1886b80);
	OFFSET(isLocalPlayerController, 0x6A0);
	OFFSET(dwEntityList, 0x17995c0);
	OFFSET(dwViewMatrix, 0x1887730);
	OFFSET(dwJump, 0x169F370); 
	OFFSET(dwViewAngles, 0x18DAAF0);

	OFFSET(m_fFlags, 0x3C8);
	OFFSET(m_PlayerPawn, 0x7BC);
	OFFSET(m_sPlayerPawnName, 0x610);
	OFFSET(m_iTeamNum, 0x3bf);
	OFFSET(m_isAlive, 0x7C4);
	OFFSET(m_pawnHealth, 0x812);
	OFFSET(m_pawnArmor, 0x7CC);
	OFFSET(m_lifeState, 0x330);
	OFFSET(m_vecOrigin, 0x1214);
}

#undef OFFSET