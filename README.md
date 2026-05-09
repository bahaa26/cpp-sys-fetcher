# C++ Hardware Metric Fetcher (Windows CLI)

A lightweight, high-performance command-line utility built in C++17 that queries the Windows Operating System for real-time hardware utilization metrics. 

This project was built to explore system-level programming, interacting directly with the native Windows API (`<windows.h>`), and handling memory and system resource queries safely in C++.

## Features
- **Zero External Dependencies:** Built entirely using the C++ Standard Library and the native Windows API.
- **Real-Time RAM Usage:** Fetches total physical memory and currently available memory.
- **System Uptime:** Calculates exactly how long the machine has been running.
- **Disk Space Monitoring:** Checks the total and free space on the primary OS drive.
- **CPU Load Calculation:** Calculates current CPU utilization using system idle times (in development).

## Technical Stack
- **Language:** C++17
- **Compiler:** WinLibs GCC (MinGW-w64) 15.2.0
- **Key Libraries:** `<windows.h>`, `<iostream>`, `<iomanip>`
- **Build System:** VS Code `tasks.json`

## Project Structure
```text
cpp-sys-fetcher/
├── src/
│   ├── main.cpp               # Entry point and CLI UI
│   ├── system_monitor.cpp     # Windows API implementation
│   └── system_monitor.h       # SystemMonitor class definition
├── .vscode/
│   └── tasks.json             # GCC build configuration
└── README.md