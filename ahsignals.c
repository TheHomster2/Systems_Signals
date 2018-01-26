#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <fcntl.h>

static void sighandler(int signo){

    if (signo == SIGINT){
        int fd = open("ahsignals.txt", O_CREAT | O_WRONLY | O_APPEND, 0644);
        char str[] = "Getting out... \n";
        write(fd, str, sizeof(str));
        close(fd);
        exit(SIGINT);
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
