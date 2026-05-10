#pragma once

// This is the master header for the Windows API
#include <windows.h>
#include <string>

// A container to hold RAM data
struct RamMetrics
{
    double total_gb;
    double available_gb;
    int usage_percent;
};

// A container to hold disk data
struct DiskMetrics
{
    double total_gb;
    double free_gb;
};

class SystemMonitor
{

public:
    SystemMonitor() = default;

    // Fetch current RAM statistics
    RamMetrics get_ram_usage() const;

    // Fetch system uptime
    long long get_system_uptime_seconds() const;

    // Fetch disk space for a specific drive (default to c drive)
    DiskMetrics get_disk_space(const std::string &drive_letter = "C:\\") const;

private:
    // bytes to GB helper method
    double bytes_to_gb(DWORDLONG bytes) const;
};