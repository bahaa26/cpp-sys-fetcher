#include "system_monitor.h"

double SystemMonitor::bytes_to_gb(DWORDLONG bytes) const
{
    // 1GB = 1024 * 1024KB = 1024 * 1024 * 1024 Bytes
    return static_cast<double>(bytes) / (1024.0 * 1024.0 * 1024.0);
}

// Fetch Ram Usage
RamMetrics SystemMonitor::get_ram_usage() const
{
    // Windows struct to hold memory data
    MEMORYSTATUSEX memInfo;

    // tell windows how big the struct is
    memInfo.dwLength = sizeof(MEMORYSTATUSEX);

    // Fill memInfo with memory data
    GlobalMemoryStatusEx(&memInfo);

    RamMetrics metrics;
    metrics.total_gb = bytes_to_gb(memInfo.ullTotalPhys);
    metrics.available_gb = bytes_to_gb(memInfo.ullAvailPhys);
    metrics.usage_percent = bytes_to_gb(memInfo.dwMemoryLoad);

    return metrics;
}

// Fetch uptime
long long SystemMonitor::get_system_uptime_seconds() const
{
    return GetTickCount64() / 1000;
}

// Fetch disk space
DiskMetrics SystemMonitor::get_disk_space(const std::string& drive_letter) const
{
    ULARGE_INTEGER freeBytesAvailableToCaller;
    ULARGE_INTEGER totalNumberOfBytes;
    ULARGE_INTEGER totalNumberOfFreeBytes;

    BOOL success = GetDiskFreeSpaceExA(
        drive_letter.c_str(),
        &freeBytesAvailableToCaller,
        &totalNumberOfBytes,
        &totalNumberOfFreeBytes
    );

    DiskMetrics metrics;

    if(success) {
        metrics.total_gb = bytes_to_gb(totalNumberOfBytes.QuadPart);
        metrics.free_gb = bytes_to_gb(totalNumberOfFreeBytes.QuadPart);
    } else {
        metrics.total_gb = 0.0;
        metrics.free_gb = 0.0;
    }

    return metrics;
}

