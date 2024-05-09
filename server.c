#include <unistd.h>
#include <signal.h>
#include <sys/types.h> 
#include <stdio.h>

static void signalhandler(int signum)
{
    static int i;
    static int bit;
    
    i = 0;
    bit = 0;
    if(signum == SIGUSR1)
        i |= (1 << bit);
    bit++;
    if(bit == 8)
    {
        printf("%c", i);
        bit = 0;
        i = 0;
        usleep(100);
    }

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