#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <ctype.h>

// 프로세스 상태를 나타내는 열거형
enum state {
    RUNNING = 'R',
    SLEEPING = 'S',
    WAITING = 'D',
    ZOMBIE = 'Z',
    STOPPED = 'T',
    DEAD = 'X',
    UNKNOWN = 'U'
};

// 프로세스 정보 구조체
struct proc_info {
    pid_t pid;
    pid_t ppid;
    pid_t pgrp;
    uid_t uid;
    char state;
    char cmd[256];
};

// 프로세스 상태를 문자열로 변환하는 함수
char state_to_char(int state) {
    switch (state) {
        case 'R':
            return RUNNING;
        case 'S':
            return SLEEPING;
        case 'D':
            return WAITING;
        case 'Z':
            return ZOMBIE;
        case 'T':
            return STOPPED;
        case 'X':
            return DEAD;
        default:
            return UNKNOWN;
    }
}

// 프로세스 정보를 가져오는 함수
int get_proc_info(struct proc_info *proc, pid_t pid) {
    char proc_path[256];
    char cmd_path[256];
    FILE *fp;
    char line[1024];
    char state;
    int ppid, pgrp;
    int uid;

    // 프로세스 정보가 있는 /proc/<pid>/stat 파일 경로 생성
    sprintf(proc_path, "/proc/%d/stat", pid);

    // /proc/<pid>/stat 파일 열기
    fp = fopen(proc_path, "r");
    if (fp == NULL) {
        return -1;
    }

    // /proc/<pid>/stat 파일에서 정보 읽어오기
    fscanf(fp, "%d %s %c %d %d %d", &proc->pid, proc->cmd, &state, &ppid, &pgrp, &uid);

    // 프로세스 상태 문자열로 변환하여 저장
    proc->state = state_to_char(state);

    // 부모 프로세스 ID, 프로세스 그룹 ID, 사용자 ID 저장
    proc->ppid = ppid;
    proc->pgrp = pgrp;
    proc->uid = uid;

    // /proc/<pid>/stat 파일 닫기
    fclose(fp);

    // 프로세스 정보가 있는 /proc/<pid>/cmdline 파일 경로 생성
    sprintf(cmd_path, "/proc/%d/cmdline", pid);

    // /proc/<pid>/cmdline 파일 열기
    fp = fopen(cmd_path, "r");
    if (fp == NULL) {
        return -1;
    }

    // /proc/<pid>/cmdline 파일에서 프로세스 명령어 읽기
    fgets(line, sizeof(line), fp);
    strcpy(proc->cmd, line);

    // /proc/<pid>/cmdline 파일 닫기
    fclose(fp);

    return 0;
}

int main() {
    DIR *dir;
    struct dirent *ent;
    pid_t pid;
    struct proc_info proc;
    // /proc 디렉터리 열기
    dir = opendir("/proc");
    if (dir == NULL) {
        perror("opendir failed");
        return -1;
    }

    // 모든 프로세스 정보 출력
    printf("%-6s %-6s %-6s %-6s %-6s %s\n", "PID", "PPID", "PGID", "UID", "STATE", "COMMAND");
    while ((ent = readdir(dir)) != NULL) {
        // 디렉터리 항목이 PID인지 확인
        if (isdigit(ent->d_name[0])) {
            // PID 추출
            pid = atoi(ent->d_name);

            // 프로세스 정보 가져오기
            if (get_proc_info(&proc, pid) == 0) {
                // 프로세스 정보 출력
                printf("%-6d %-6d %-6d %-6d %-6c %s\n", proc.pid, proc.ppid, proc.pgrp, proc.uid, proc.state, proc.cmd);
            }
        }
    }

    // /proc 디렉터리 닫기
    closedir(dir);

    return 0;
}
