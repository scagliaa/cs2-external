#pragma once
#include <Windows.h>
#include <TlHelp32.h>

class process_handler
{
	HANDLE process;
	DWORD process_id;

public:
	void init();
	void free() const;
	[[nodiscard]] auto get_process() const -> HANDLE;
	[[nodiscard]] DWORD get_process_id() const;
};

inline process_handler g_process_handler;