#include "kernel/types.h"
#include "user/user.h"

int main(){
    int pid;
    int pipes1[2], pipes2[2];
    char buf[] = {'a'};
    pipe(pipes1);
    pipe(pipes2);

    int ret = fork();
    if(ret == 0){
        pid = getpid();
        close(pipes1[1]);
        close(pipes2[0]);
        read(pipes1[0], buf, 1);
        printf("%d: received ping\n", pid);
        write(pipes2[1], buf, 1);
        exit(0);
    }else{
        pid = getpid();
        close(pipes1[0]);
        close(pipes2[1]);
        write(pipes1[1], buf, 1);
        read(pipes2[0], buf, 1);
        printf("%d: received pong\n", pid);
        exit(0);
    }

}