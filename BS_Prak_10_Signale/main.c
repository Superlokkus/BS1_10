//
//  main.c
//  BS_Prak_10_Signale
//
//  Created by Markus Klemm on 01.02.14.
//  Copyright (c) 2014 net.markusklemm. All rights reserved.
//

#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void sigusr1Hdl(int sig)
{
    printf("SIGUSR1 empfangen!\n");
    signal(SIGUSR1, SIG_DFL);
}

int main(int argc, const char * argv[])
{
    
    if (signal(SIGUSR1, sigusr1Hdl) == SIG_ERR)
    {
        perror("This should never happen (Signal(SIGUSR1,) failed");
    }
    
    if (kill(getpid(), SIGUSR1)) {
        perror("First kill() failed");
    }
    
    if (kill(getpid(), SIGUSR1)) {
        perror("Second kill() failed");
    }
    
    
    

    return 0;
}

