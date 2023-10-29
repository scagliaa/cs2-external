#include <ranges>
#include <span>
#include <algorithm>
#include <memory>

#include "Process/Process.h"
namespace utils {
    template <typename T>
    auto read(const DWORD& dw_address) -> T
    {
        T buffer;
        std::ranges::copy(std::span(reinterpret_cast<PBYTE>(dw_address), sizeof(T)), std::span(reinterpret_cast<PBYTE>(&buffer), sizeof(T)));
        return buffer;
    }

    template <typename T>
    void write(const DWORD& dw_address, const T& buffer)
    {
        std::ranges::copy(std::span(reinterpret_cast<const PBYTE>(&buffer), sizeof(T)), std::span(reinterpret_cast<PBYTE>(dw_address), sizeof(T)));
    }

    inline auto get_module_address(const wchar_t* wsz_module_name) -> DWORD
    {
        MODULEENTRY32 mod_entry;
        mod_entry.dwSize = sizeof(MODULEENTRY32);
        auto* const h_snapshot = CreateToolhelp32Snapshot(0x18, g_process_handler.get_process_id());
        Module32First(h_snapshot, &mod_entry);

        bool module_found = Module32Next(h_snapshot, &mod_entry);
        while (module_found) {
            if (wcscmp(mod_entry.szModule, wsz_module_name) == 0) {
                CloseHandle(h_snapshot);
                return reinterpret_cast<DWORD>(mod_entry.hModule);
            }
            module_found = Module32Next(h_snapshot, &mod_entry);
        }

        CloseHandle(h_snapshot);
        return 0x0;
    }
}