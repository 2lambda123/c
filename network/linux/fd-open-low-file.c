#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// gcc fd-open-low-file.c -o bin
// ./bin
int main(void) {
    int fd;
    char buf[] = "Let's go!\n";
    // fcntl - open(const char *pathname, int flags, mode_t mode)
    // O_CREAT: 파일이 없으면 생성
    // O_TRUNC: 기존 내용 삭제
    // O_APPEND: 기존 내용 끝에 추가
    // O_RDONLY: 읽기 전용
    // O_WRONLY: 쓰기 전용
    // O_RDWR: 읽기/쓰기 겸용
    fd = open("data.txt", O_CREAT | O_WRONLY | O_TRUNC);
    if (fd == -1) {
        perror("open() error");
        exit(1);
    }

    // 3이 출력됨.
    // 0, 1, 2는 기본적으로 표준 입력, 표준 출력, 표준 에러에 할당됨.
    printf("file descriptor: %d\n", fd);

    // unistd.h - write(int fd, const void *buf, size_t nbytes)
    if (write(fd, buf, sizeof(buf)) == -1) {
        perror("write() error");
        exit(1);
    }

    close(fd);

    return 0;
}
