#include <stdio.h>

#include <winsock2.h>

#pragma comment(lib, "Ws2_32.lib") // Winsock 라이브러리 링크

int main() {
    WSADATA wsa;
    SOCKET server_socket, new_socket;
    struct sockaddr_in server, client;
    int client_size = sizeof(client);
    char buffer[1024] = {0};

    // Winsock 초기화
    if (WSAStartup(MAKEWORD(2, 2), &wsa) != 0) {
        printf("Winsock 초기화 실패. 오류 코드: %d\n", WSAGetLastError());
        return 1;
    }

    // 1. 소켓 생성 socket()
    if ((server_socket = socket(AF_INET, SOCK_STREAM, 0)) == INVALID_SOCKET) {
        printf("소켓 생성 실패. 오류 코드: %d\n", WSAGetLastError());
        return 1;
    }

    // AF: Address Family, PF: Protocol Family
    server.sin_family = AF_INET;
    // INADDR_ANY: 모든 IP 주소
    server.sin_addr.s_addr = INADDR_ANY;

    // https://learn.microsoft.com/ko-kr/windows/win32/api/winsock2/nf-winsock2-htons
    server.sin_port = htons(8080); // 포트 번호

    // 2. 소켓 주소와 포트를 바인딩 bind()
    if (bind(server_socket, (struct sockaddr *) &server, sizeof(server)) == SOCKET_ERROR) {
        printf("바인딩 실패. 오류 코드: %d\n", WSAGetLastError());
        return 1;
    }

    // 3. 리스닝 시작 listen()
    if (listen(server_socket, 3) == SOCKET_ERROR) {
        printf("리스닝 시작 실패. 오류 코드: %d\n", WSAGetLastError());
        return 1;
    }

    printf("서버가 8080 포트에서 대기 중...\n");

    // 4. 클라이언트 연결을 기다림 accept()
    if ((new_socket = accept(server_socket, (struct sockaddr *) &client, &client_size)) == INVALID_SOCKET) {
        printf("클라이언트 연결 실패. 오류 코드: %d\n", WSAGetLastError());
        return 1;
    }

    // 데이터를 받아 콘솔에 출력
    while (1) {
        int read_data = recv(new_socket, buffer, sizeof(buffer), 0);
        if (read_data <= 0)
            break;
        printf("%s", buffer);
        memset(buffer, 0, sizeof(buffer));
    }

    // 소켓 닫기
    closesocket(server_socket);
    closesocket(new_socket);

    // Winsock 종료
    WSACleanup();

    return 0;
}
