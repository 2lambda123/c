#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/socket.h>

// gcc fd-socket.c -o bin
// ./bin
int main(void) {
    int fd1, fd2, fd3;
    fd1 = socket(PF_INET, SOCK_STREAM, 0);
    fd2 = open("test.dat", O_CREAT | O_WRONLY | O_TRUNC);
    fd3 = socket(PF_INET, SOCK_DGRAM, 0);

    printf("file descriptor 1: %d\n", fd1); // 3
    printf("file descriptor 2: %d\n", fd2); // 4
    printf("file descriptor 3: %d\n", fd3); // 5

    close(fd1);
    close(fd2);
    close(fd3);

    return 0;
}
