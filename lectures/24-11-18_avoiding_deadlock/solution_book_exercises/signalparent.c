#include "csapp.h"

int counter = 0;

void handler(int sig)
{
    counter ++ ; 
    // sleep(3);
    return;
}


int main()
{
    int i;
    signal(SIGUSR2, handler);

    if (fork() == 0) {
        for (i = 0; i < 5; i++) {
            kill(getppid(), SIGUSR2);
            printf("sent SIGUSR2 to parent\n");
        }
        exit(0);
    }

    wait(NULL);
    printf("counter=%d\n", counter);   
    exit(0);

}
