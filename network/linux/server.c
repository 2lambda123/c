#include <stdio.h>
#include <stdlib.h>
#include <arpa/inet.h>
#include <string.h>
#include <unistd.h>

// ref: 열혈 tcp/ip 소켓 프로그래밍
int main(int argc, char *argv[]) {
    int serv_sock;
    int clnt_sock;

    // 서버 주소 구조체(inet.h)
    struct sockaddr_in serv_addr;
    struct sockaddr_in clnt_addr;
    socklen_t clnt_addr_size;

    char message[] = "Hello World!";

    // 서버 소켓 생성
    if (argc != 2) {
        printf("Usage: %s <port>\n", argv[0]);
        exit(1);
    }

    serv_sock = socket(PF_INET, SOCK_STREAM, 0);
    if (serv_sock == -1) {
        perror("socket() error");
        exit(1);
    }

    // 서버 주소 설정
    // string.h - memset(void *ptr, int value, size_t num)
    memset(&serv_addr, 0, sizeof(serv_addr)); // 0으로 초기화
    serv_addr.sin_family = AF_INET; // IPv4 주소체계
    serv_addr.sin_addr.s_addr = htonl(INADDR_ANY); // 32bit IPv4 주소
    // serv_addr.sin_port = htons(atoi(argv[1])); // 서버 포트
    serv_addr.sin_port = htons(9190); // 서버 포트

    // 서버 소켓에 주소 할당
    if (bind(serv_sock, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) == -1) {
        perror("bind() error");
        exit(1);
    }

    // 연결 요청 대기 상태로 진입
    if (listen(serv_sock, 5) == -1) {
        perror("listen() error");
        exit(1);
    }

    // 연결 요청 수락
    clnt_addr_size = sizeof(clnt_addr);
    clnt_sock = accept(serv_sock, (struct sockaddr*)&clnt_addr, &clnt_addr_size);
    if (clnt_sock == -1) {
        perror("accept() error");
        exit(1);
    }

    // 데이터 전송
    // unistd.h - write(int fd, const void *buf, size_t nbytes)
    write(clnt_sock, message, sizeof(message));
    close(clnt_sock);
    close(serv_sock);

    return 0;
}
