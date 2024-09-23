#include <iostream>
#include "manager.h"

// Call allocate_map to initialize the data structure
void test_allocate_map()
{
    PIDManager pid_manager;
    int result = pid_manager.allocate_map();
    std::cout << "Test Case 1: Initializing PID map..." << std::endl;
    if (result == 1)
    {
        std::cout << "Passed - PID map is initialized.\n"
                  << std::endl;
    }
    else
    {
        std::cout << "Failed - PID map is not initialized.\n"
                  << std::endl;
    }
}

// Call allocate_pid multiple times to allocate PIDs.
void test_allocate_pid()
{
    PIDManager pid_manager;
    pid_manager.allocate_map();

    std::cout << "Test Case 2: Allocating PIDs..." << std::endl;
    bool passed = true;
    for (int i = 0; i < 5; ++i)
    {
        int pid = pid_manager.allocate_pid();
        if (pid >= MIN_PID && pid <= MAX_PID)
        {
            std::cout << "Allocated PID: " << pid << std::endl;
        }
        else
        {
            passed = false;
            std::cout << "Failed - PIDs are not allocated.\n"
                      << std::endl;
        }
    }
    std::cout << std::endl;
}

// Check if the allocated PIDs fall within the specified range.
void test_pid_range()
{
    PIDManager pid_manager;
    pid_manager.allocate_map();
    int pid1 = pid_manager.allocate_pid();
    int pid2 = pid_manager.allocate_pid();

    std::cout << "Test Case 3: Checking PID range..." << std::endl;
    if ((pid1 >= MIN_PID && pid1 <= MAX_PID) && (pid2 >= MIN_PID && pid2 <= MAX_PID))
    {
        std::cout << "Passed - PIDs are within range.\n"
                  << std::endl;
    }
    else
    {
        std::cout << "Failed - PIDS are not within range.\n"
                  << std::endl;
    }
}

// Call release_pid for each allocated PID.
void test_release_pid()
{
    PIDManager pid_manager;
    pid_manager.allocate_map();

    int pids[5];
    std::cout << "Test Case 4: Releasing PIDs..." << std::endl;
    for (int i = 0; i < 5; ++i)
    {
        int pid = pid_manager.allocate_pid();
        if (pid != -1)
        {
            pids[i] = pid;
        }
    }
    for (int i = 0; i < 5; ++i)
    {
        pid_manager.release_pid(pids[i]);
        std::cout << "Released PID: " << pids[i] << std::endl;
    }
}

// Check if the released PIDs become available for allocation again.
void test_relocate_pid()
{
    PIDManager pid_manager;
    pid_manager.allocate_map();

    int pids[5];
    std::cout << "\nTest Case 5: Relocating PIDs..." << std::endl;
    for (int i = 0; i < 5; ++i)
    {
        int pid = pid_manager.allocate_pid();
        if (pid != -1)
        {
            pids[i] = pid;
        }
    }
    for (int i = 0; i < 5; ++i)
    {
        pid_manager.release_pid(pids[i]);
    }
    for (int i = 0; i < 5; ++i)
    {
        int relocated_pid = pid_manager.allocate_pid();
        if (relocated_pid == pids[i])
        {
            std::cout << "Relocated PID: " << relocated_pid << std::endl;
        }
    }
    std::cout << std::endl;
}

void run_tests()
{
    test_allocate_map();
    test_allocate_pid();
    test_pid_range();
    test_release_pid();
    test_relocate_pid();
}