#include "manager.h"

// initialize PID map
int PIDManager::allocate_map()
{
    return 1;
}

// allocate PID
int PIDManager::allocate_pid()
{
    for (int i = 0; i < PID_RANGE; ++i)
    {
        if (!pid_bitmap[i])
        {
            pid_bitmap.set(i);
            return MIN_PID + i;
        }
    }
    return -1;
}

// release PID
void PIDManager::release_pid(int pid)
{
    if (pid >= MIN_PID && pid <= MAX_PID)
    {
        pid_bitmap.reset(pid - MIN_PID);
    }
}