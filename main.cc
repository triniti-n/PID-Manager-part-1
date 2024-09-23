#include <iostream>
#include <sys/types.h>
#include <unistd.h>
#include <bitset>

#include "manager.h"

void run_tests();

int main()
{
    std::cout << "Running process manager and test cases..." << std::endl;

    pid_t pid = fork();
    if (pid < 0)
    {
        std::cout << "Fork failed" << std::endl;
        return -1;
    }
    else if (pid == 0)
    {
        // Child process
        std::cout << "\n[Child Process]\n"
                  << std::endl;
        run_tests();
        std::cout << "+++++++++++++++++++++++++++++++++++++++++\n";
    }
    else
    {
        // Parent process
        std::cout << "\n[Parent Process]\n"
                  << std::endl;
        run_tests();
        std::cout << "+++++++++++++++++++++++++++++++++++++++++\n";
    }

    return 0;
}