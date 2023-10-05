#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/*

Here is an example of the output of the program:



----------------------------------------------------

Hello Sys!

Parent process PID is: 37033
My PID after fork is: 37034
My PID using getpid is: 37033
My parent PID using getppid is: 32972
My PID after fork is: 0
My PID using getpid is: 37034
My parent PID using getppid is: 549


----------------------------------------------------



one weird thing is that each time I run it I have this: My parent PID using getppid is: 549
I tryed to search in google but couldn't find anything for now
Then I searched for this process and here is what I found:


------------------------------------------------------------------------------------------------------------------------------------
$ ps aux | grep 549
user        549  0.0  0.0  21648 12996 ?        Ss   Oct04   0:01 /usr/lib/systemd/systemd --user
------------------------------------------------------------------------------------------------------------------------------------

Then also this My parent PID using getppid is: 32972 is always the same I searched for the process and it was the process of the active shell I was using.

------------------------------------------------------------------------------------------------------------------------------------
$ ps aux | grep 32972
user      32972  0.0  0.0   8300  4480 pts/2    Ss+  14:47   0:00 /usr/bin/bash --init-file /opt/visual-studio-code/resources/app/out/vs/workbench/contrib/terminal/browser/media/shellIntegration-bash.sh
------------------------------------------------------------------------------------------------------------------------------------

I Openned another terminal and here are the results:

----------------------------------------------------
Hello Sys!
Parent process PID is: 37287
P value after fork is: 37288
My PID using getpid is: 37287
My parent PID using getppid is: 37186
P value after fork is: 0
My PID using getpid is: 37288
My parent PID using getppid is: 549

----------------------------------------------------

As you see here the parent PID is different from the previous one.
But the 549 is still the same.

We know that this pid=549 is the systemd process.
But why it's printed in the last line of the output?
While it was the the program of the child process that printed it.


*/

int main() {
    printf("Hello Sys!\n");
    int p = getpid();
    printf("Parent process PID is: %d\n", p);
    
    p = fork();
    printf("P value after fork is: %d\n", p);
    // pid using getpid
    printf("My PID using getpid is: %d\n", getpid());
    // parent pid
    printf("My parent PID using getppid is: %d\n", getppid());

    return 0;
}

