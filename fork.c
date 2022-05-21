#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

// parent çocuğun pid'sini alıyor diğeri alamıyor
// pid'yi orijinal sıfır olarak kabul ediyor
// bu forkta atanmış değeri alamadığı için onun da child olduğunu anlıyoruz
int main(int argc, char *argv[])
{
    if(argc!=4)
    {
        printf("2 sayı ve .txt uzantı ismini girmelisin");
        exit(1);
    }


    int n1 = atoi(argv[1]);
    int n2 = atoi(argv[2]);
    FILE *fp;
    fp = fopen(argv[3], "w");

    int pid;
    pid = fork();
    int pid2;
    if (pid > 0)
    {
        // parent
        // printf("parent: %d  ben parent pid: %d\n", pid, getpid());
        // parent
        fprintf(fp, "%d + %d = %d\n", n1, n2, n1 + n2);
        printf("%d + %d = %d\n", n1, n2, n1 + n2);
    }
    else if (pid == 0)
    {
        // child
        // printf("child: %d  ben çocuk pid: %d\n", pid, getpid());
        fprintf(fp, "%d / %d = %d\n", n1, n2, n1 / n2);
        printf("%d / %d = %d\n", n1, n2, n1 / n2);
                    pid2 = fork();

    }
    if (pid2 > 0)
    {

        // printf("parent: %d  ben parent pid: %d\n", pid2, getpid());
        fprintf(fp, "%d - %d = %d\n", n1, n2, n1 - n2);
        printf("%d - %d = %d\n", n1, n2, n1 - n2);
    }
    else if (pid2 == 0)
    {
        // child
        // printf("child: %d  ben çocuk pid: %d\n", pid2, getpid());
        fprintf(fp, "%d * %d = %d\n", n1, n2, n1 * n2);
        printf("%d * %d = %d\n", n1, n2, n1 * n2);
    }
}
