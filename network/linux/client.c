#include <stdio.h>
#include <stdlib.h>
#include <arpa/inet.h>
#include <string.h>
#include <unistd.h>

// gcc client.c -o client
// ./client 127.0.0.1 9190
int main(int argc, char *argv[]) {
    int sock;
    struct sockaddr_in serv_addr;
    char message[30];
    int str_len;

    if (argc != 3) {
        printf("Usage: %s <IP> <port>\n", argv[0]);
        exit(1);
    }

    // socket()
    sock = socket(PF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        perror("socket() error");
        exit(1);
    }

    // connect()
    memset(&serv_addr, 0, sizeof(serv_addr)); // 0으로 초기화
    serv_addr.sin_family = AF_INET; // IPv4 주소체계
    serv_addr.sin_addr.s_addr = inet_addr(argv[1]); // 32bit IPv4 주소
    serv_addr.sin_port = htons(atoi(argv[2])); // 서버 포트

    if (connect(sock, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) == -1) {
        perror("connect() error");
        exit(1);
    }

    // read()
    str_len = read(sock, message, sizeof(message) - 1);
    if (str_len == -1) {
        perror("read() error");
        exit(1);
    }

    printf("Message from server: %s\n", message);
    close(sock);

    return 0;
}

google-drive-ocamlfuse                                                                                                  ✭ ✱
[88291:88291:0100/000000.735442:ERROR:gbm_wrapper.cc(253)] Failed to export buffer to dma_buf: No such file or directory (2)
[88291:88291:0100/000000.735537:ERROR:gbm_wrapper.cc(253)] Failed to export buffer to dma_buf: No such file or directory (2)
[88291:88291:0100/000000.735581:ERROR:gbm_wrapper.cc(253)] Failed to export buffer to dma_buf: No such file or directory (2)
[88291:88291:0100/000000.735624:ERROR:gbm_wrapper.cc(253)] Failed to export buffer to dma_buf: No such file or directory (2)
[88291:88291:0100/000000.735872:ERROR:gbm_wrapper.cc(253)] Failed to export buffer to dma_buf: No such file or directory (2)
[88291:88291:0100/000000.735918:ERROR:gbm_wrapper.cc(253)] Failed to export buffer to dma_buf: No such file or directory (2)
[88291:88291:0100/000000.735961:ERROR:gbm_wrapper.cc(253)] Failed to export buffer to dma_buf: No such file or directory (2)
[88291:88291:0100/000000.736003:ERROR:gbm_wrapper.cc(253)] Failed to export buffer to dma_buf: No such file or directory (2)
[88291:88291:0100/000000.736044:ERROR:gbm_wrapper.cc(253)] Failed to export buffer to dma_buf: No such file or directory (2)
[88291:88291:0100/000000.736086:ERROR:gbm_wrapper.cc(253)] Failed to export buffer to dma_buf: No such file or directory (2)
[88291:88291:0100/000000.736127:ERROR:gbm_wrapper.cc(253)] Failed to export buffer to dma_buf: No such file or directory (2)
[88291:88291:0100/000000.736169:ERROR:gbm_wrapper.cc(253)] Failed to export buffer to dma_buf: No such file or directory (2)
[88291:88291:0100/000000.736211:ERROR:gbm_wrapper.cc(253)] Failed to export buffer to dma_buf: No such file or directory (2)
[88291:88291:0100/000000.736254:ERROR:gbm_wrapper.cc(253)] Failed to export buffer to dma_buf: No such file or directory (2)
[88291:88291:0100/000000.736296:ERROR:gbm_wrapper.cc(253)] Failed to export buffer to dma_buf: No such file or directory (2)
[88291:88291:0100/000000.736339:ERROR:gbm_wrapper.cc(253)] Failed to export buffer to dma_buf: No such file or directory (2)
[88291:88291:0100/000000.736383:ERROR:gbm_wrapper.cc(253)] Failed to export buffer to dma_buf: No such file or directory (2)
[88291:88291:0100/000000.736428:ERROR:gbm_wrapper.cc(253)] Failed to export buffer to dma_buf: No such file or directory (2)
[88291:88291:0100/000000.736472:ERROR:gbm_wrapper.cc(253)] Failed to export buffer to dma_buf: No such file or directory (2)
[88291:88291:0100/000000.736515:ERROR:gbm_wrapper.cc(253)] Failed to export buffer to dma_buf: No such file or directory (2)
[88291:88291:0100/000000.736557:ERROR:gbm_wrapper.cc(253)] Failed to export buffer to dma_buf: No such file or directory (2)
[88291:88291:0100/000000.736599:ERROR:gbm_wrapper.cc(253)] Failed to export buffer to dma_buf: No such file or directory (2)
[88291:88291:0100/000000.736642:ERROR:gbm_wrapper.cc(253)] Failed to export buffer to dma_buf: No such file or directory (2)
[88291:88291:0100/000000.736684:ERROR:gbm_wrapper.cc(253)] Failed to export buffer to dma_buf: No such file or directory (2)
[88291:88291:0100/000000.736726:ERROR:gbm_wrapper.cc(253)] Failed to export buffer to dma_buf: No such file or directory (2)
[88291:88291:0100/000000.736767:ERROR:gbm_wrapper.cc(253)] Failed to export buffer to dma_buf: No such file or directory (2)
[88291:88291:0100/000000.736808:ERROR:gbm_wrapper.cc(253)] Failed to export buffer to dma_buf: No such file or directory (2)
[88291:88291:0100/000000.736850:ERROR:gbm_wrapper.cc(253)] Failed to export buffer to dma_buf: No such file or directory (2)
[88291:88291:0100/000000.736892:ERROR:gbm_wrapper.cc(253)] Failed to export buffer to dma_buf: No such file or directory (2)
[88291:88291:0100/000000.736933:ERROR:gbm_wrapper.cc(253)] Failed to export buffer to dma_buf: No such file or directory (2)
[88291:88291:0100/000000.736975:ERROR:gbm_wrapper.cc(253)] Failed to export buffer to dma_buf: No such file or directory (2)
[88291:88291:0100/000000.737017:ERROR:gbm_wrapper.cc(253)] Failed to export buffer to dma_buf: No such file or directory (2)
[88291:88291:0100/000000.737060:ERROR:gbm_wrapper.cc(253)] Failed to export buffer to dma_buf: No such file or directory (2)
[88291:88291:0100/000000.737108:ERROR:gbm_wrapper.cc(253)] Failed to export buffer to dma_buf: No such file or directory (2)
[88291:88291:0100/000000.737152:ERROR:gbm_wrapper.cc(253)] Failed to export buffer to dma_buf: No such file or directory (2)
[88291:88291:0100/000000.737195:ERROR:gbm_wrapper.cc(253)] Failed to export buffer to dma_buf: No such file or directory (2)
[88291:88291:0100/000000.737237:ERROR:gbm_wrapper.cc(253)] Failed to export buffer to dma_buf: No such file or directory (2)
[88291:88291:0100/000000.737279:ERROR:gbm_wrapper.cc(253)] Failed to export buffer to dma_buf: No such file or directory (2)
[88291:88291:0100/000000.737320:ERROR:gbm_wrapper.cc(253)] Failed to export buffer to dma_buf: No such file or directory (2)
[88291:88291:0100/000000.737363:ERROR:gbm_wrapper.cc(253)] Failed to export buffer to dma_buf: No such file or directory (2)
Access token retrieved correctly.
