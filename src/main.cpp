#include <iostream>
#include <iomanip>
#include <thread>
#include <chrono>
#include "system_monitor.h"

void clear_screen()
{
    system("cls");
}

int main()
{
    while (true)
    {
        clear_screen();
        SystemMonitor monitor;
        RamMetrics ram = monitor.get_ram_usage();
        long long uptime = monitor.get_system_uptime_seconds();
        DiskMetrics disk = monitor.get_disk_space("E:\\");

        long long hours = uptime / 3600;
        long long minutes = (uptime % 3600) / 60;
        long long seconds = uptime % 60;

        // 3. Print the UI
        std::cout << "=========================================\n";
        std::cout << "        WINDOWS HARDWARE MONITOR         \n";
        std::cout << "=========================================\n\n";

        // Memory Section
        std::cout << "[ MEMORY ]\n";
        std::cout << std::left << std::setw(20) << "Total RAM:"
                  << std::fixed << std::setprecision(2) << ram.total_gb << " GB\n";
        std::cout << std::left << std::setw(20) << "Available RAM:"
                  << ram.available_gb << " GB\n";
        std::cout << std::left << std::setw(20) << "Usage:"
                  << ram.usage_percent << " %\n\n";

        // Storage Section
        std::cout << "[ STORAGE (C:\\) ]\n";
        std::cout << std::left << std::setw(20) << "Total Space:"
                  << disk.total_gb << " GB\n";
        std::cout << std::left << std::setw(20) << "Free Space:"
                  << disk.free_gb << " GB\n\n";

        // System Section
        std::cout << "[ SYSTEM ]\n";
        std::cout << std::left << std::setw(20) << "Uptime:"
                  << hours << "h " << minutes << "m " << seconds << "s\n\n";

        std::cout << "=========================================\n";
        std::cout << "Press Ctrl+C to exit...\n";

        // 4. Pause for exactly 1 second before the loop restarts
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }

    return 1;
}