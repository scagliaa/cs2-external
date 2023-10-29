#include <iostream>
#include <Windows.h>
#include <string>

class process_handler {
private:
    const wchar_t* wsz_window_name = L"Counter-Strike 2";
    HANDLE process = nullptr;
    DWORD process_id = 0;

public:
    auto init() -> void
    {
        auto get_proc_id = [&]() -> DWORD {
            const HWND window_handle = FindWindow(nullptr, wsz_window_name);
            if (window_handle == nullptr) {
                std::cout << "Failed to find window" << std::endl;
                return 0;
            }

            DWORD proc_id;
            GetWindowThreadProcessId(window_handle, &proc_id);
            return proc_id;
        };

        process_id = get_proc_id();

        while (process == nullptr)
            process = OpenProcess(PROCESS_ALL_ACCESS, FALSE, process_id);
    }

    void free() const
    {
        CloseHandle(process);
    }

    auto get_process() const -> HANDLE
    {
        return process;
    }

    auto get_process_id() const -> DWORD
    {
        return process_id;
    }
};