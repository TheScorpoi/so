#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

struct inf {
    int avail_r1, avail_r2, avail_r3;
} info;

int main(int argc, char const *argv[]) {
    printf("r1: %d\n", info.avail_r1);
}
