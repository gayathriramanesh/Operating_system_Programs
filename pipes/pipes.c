#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>
int main()
{
    int fd[2];
    int pid;
    char msg[4] = {'S', 'S', 'N', '\0'};
    char msg1[4];
    //create a pipe
    if (pipe(fd) == -1)
    {
        printf("pipe creation is error\n");
    }
    else
    {
        printf("Pipe creation is successful\n");
    }
    //create a parent and child process
    pid = fork();
    if (pid > 0)
    {
        //write in the pipe of parent process so that child reads it
        printf("Iam a parent process\n");
        printf("Parent--->My message is %s\n", msg);
        write(fd[1], msg, sizeof(msg));
    }
    else
    {
        printf("Iam a child process\n");
        //check if written msg is written in pipe by reading from the pipe in child process 
        read(fd[0], msg1, sizeof(msg1));
        printf("Child--->Msg from my parent is %s\n", msg1);
    }
    return 0;
}