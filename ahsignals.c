#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <fcntl.h>

static void sighandler(int signo){

    if (signo == SIGINT){
        printf("Getting out...\n");
        exit(1);
    }

    if (signo == SIGSTOP){
        printf("PPID: %d\n", getppid());
        
    }
}

int main(){

signal(SIGINT, sighandler);
signal(SIGSTOP, sighandler);

while(1){
    printf ("PID: %d\n", getpid());
    sleep(1);
}

return 0;

}
