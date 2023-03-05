#include <stdio.h>
//#include <stdlib.h>

// clang -o mv.o mv.c
// mv <source> <destination>
int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <source> <destination>\n", argv[0]);
        return 1;
    }
    if (rename(argv[1], argv[2]) == -1) {
        perror("rename");
        return 1;
    }
    return 0;
}
