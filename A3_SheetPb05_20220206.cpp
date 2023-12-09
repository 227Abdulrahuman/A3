// File name:A3_SheetPb05_20220206
// Purpose: Create a C++ program for a basic task manager to display and organize running processes on an operating system.
// Author(s):Abdelmonaem Mahmoud
// ID(s):20220206
// Section:S5
// Date:7/12/2023

#include <iostream>
#include <vector>
#include <algorithm>
#include <windows.h>
#include <tlhelp32.h>

using namespace std;

class Process {
private:
    string name;
    DWORD pid;
    SIZE_T memoryUsage;  // In bytes

public:
    Process(const string& n, DWORD p, SIZE_T mem) : name(n), pid(p), memoryUsage(mem) {}

    // Accessor methods
    string getName() const {
        return name;
    }

    DWORD getPID() const {
        return pid;
    }

    SIZE_T getMemoryUsage() const {
        return memoryUsage;
    }
};

class ProcessList {
private:
    vector<Process> processes;

public:
    // Function to load the list of processes from the operating system
    void loadProcesses() {
        // Clear existing processes
        processes.clear();

        // Get the list of processes using Windows API
        HANDLE snapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
        if (snapshot != INVALID_HANDLE_VALUE) {
            PROCESSENTRY32 processEntry;
            processEntry.dwSize = sizeof(PROCESSENTRY32);

            if (Process32First(snapshot, &processEntry)) {
                do {
                    Process process(processEntry.szExeFile, processEntry.th32ProcessID, processEntry.dwSize);
                    processes.push_back(process);
                } while (Process32Next(snapshot, &processEntry));
            }

            CloseHandle(snapshot);
        }
    }

    // Function to display processes sorted by name
    void displayByName() {
        sort(processes.begin(), processes.end(), [](const Process& a, const Process& b) {
            return a.getName() < b.getName();
        });

        displayProcesses();
    }

    // Function to display processes sorted by PID
    void displayByPID() {
        sort(processes.begin(), processes.end(), [](const Process& a, const Process& b) {
            return a.getPID() < b.getPID();
        });

        displayProcesses();
    }

    // Function to display processes sorted by memory usage
    void displayByMemoryUsage() {
        sort(processes.begin(), processes.end(), [](const Process& a, const Process& b) {
            return a.getMemoryUsage() < b.getMemoryUsage();
        });

        displayProcesses();
    }

private:
    // Helper function to display the processes
    void displayProcesses() const {
        for (const auto& process : processes) {
            cout << "Name: " << process.getName() << ", PID: " << process.getPID() << ", Memory Usage: " << process.getMemoryUsage() << " bytes" << endl;
        }
    }
};

int main() {
    ProcessList processList;

    // Load processes from the OS
    processList.loadProcesses();

    // Display processes sorted by name
    cout << "Processes sorted by name:" << endl;
    processList.displayByName();

    // Display processes sorted by PID
    cout << "\nProcesses sorted by PID:" << endl;
    processList.displayByPID();

    // Display processes sorted by memory usage
    cout << "\nProcesses sorted by memory usage:" << endl;
    processList.displayByMemoryUsage();

    return 0;
}
