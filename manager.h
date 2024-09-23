#ifndef MANAGER_H
#define MANAGER_H
#include <bitset>

#define MIN_PID 100
#define MAX_PID 1000
#define PID_RANGE (MAX_PID - MIN_PID + 1)

class PIDManager
{
private:
    std::bitset<PID_RANGE> pid_bitmap;

public:
    int allocate_map();        // initialize pids
    int allocate_pid();        // allocates and return pids
    void release_pid(int pid); // release pid
};

#endif