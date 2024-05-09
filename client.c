// #include minitalk.h
#include <unistd.h>
#include <signal.h>
#include <stdio.h>

static void send_message(int pid, char argv)
{
    int bit;
    
    bit = 0;
    while(bit < 8)
    {
        if(argv & (1 << bit))
            kill(pid, SIGUSR1);
        else 
            kill(pid, SIGUSR2);
        bit++;
    }
}

int main(int argc, char **argv)
{
    int i;
    int pid;

    i = 0;
    if(argc != 3)
    {
        printf("WRONG FORMAT!");
        return 0;
    }
    pid = atoi(argv[1]);
    while(argv[2][i])
    {
        send_message(pid,argv[2][i]);
        i++;
    }
}