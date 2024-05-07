#include <unistd.h>
#include <stdio.h>

static void signalhandler(int signum)
{

}
int main(void)
{
    pid_t pid;

    pid = getpid();
    printf("PID: %d\n", pid);
    signal(SIGUSR1, signalhandler);
    signal(SIGUSR2, signalhandler);
    while(1)
        usleep(1);
    return 0;
}