#include <stdlib.h>
#include <stdio.h>

int main() {
    char numStr [] = "23\0";
    int num = atoi(numStr);
    printf("%d", num);
    return 0;
}