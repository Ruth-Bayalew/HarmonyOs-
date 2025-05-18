#include <stdio.h>     // Provides input and output functions like printf() and scanf()
#include <stdlib.h>    // Provides general utility functions like exit(), memory allocation, etc.
#include <signal.h>    // Declares signal-related functions and constants (e.g., SIGKILL, kill())
#include <unistd.h>    // Provides access to the POSIX API, including the kill() function and pid_t type
#include <errno.h>     // Defines the integer variable errno, which is set when errors occur (used by perror())

int main() {
    pid_t target_pid;
    int signal_number;

    printf("Enter the target PID (process ID) to send a signal to: ");
    scanf("%d", &target_pid);

    printf("Enter the signal number to send (e.g., 9 for SIGKILL, 15 for SIGTERM, 2 for SIGINT): ");
    scanf("%d", &signal_number);

    // Send the chosen signal to the target process
    if (kill(target_pid, signal_number) == 0) {
        printf("Signal %d sent to process %d successfully.\n", signal_number, target_pid);
    } else {
        perror("Failed to send signal");
    }

    return 0;
}
