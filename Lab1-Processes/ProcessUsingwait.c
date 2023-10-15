#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
/*

Hello Sys!
 Process using waitParent process PID is: 12308
P value after fork is: 12309
My PID using getpid is: 12308
My parent PID using getppid is: 10983
Parent process is waiting for child process to finish
P value after fork is: 0
My PID using getpid is: 12309
My parent PID using getppid is: 12308
Child process PID is: 12309
Child process parent PID is: 12308
Child process is sleeping for 5 seconds
Child process is awake
Child process is exiting
Parent process is exiting



*/

int main() {
    printf("Hello Sys!\n Process using wait");
    int p = getpid();
    printf("Parent process PID is: %d\n", p);
    
    p = fork();
    printf("P value after fork is: %d\n", p);
    // pid using getpid
    printf("My PID using getpid is: %d\n", getpid());
    // parent pid
    printf("My parent PID using getppid is: %d\n", getppid());
    
    if (p == 0) {
        printf("Child process PID is: %d\n", getpid());
        printf("Child process parent PID is: %d\n", getppid());
        printf("Child process is sleeping for 5 seconds\n");
        sleep(5);
        printf("Child process is awake\n");
        printf("Child process is exiting\n");
        exit(0);
    }
    else {
        printf("Parent process is waiting for child process to finish\n");
        wait(NULL);
        printf("Parent process is exiting\n");
        return 0;
    }

    return 0;
}

