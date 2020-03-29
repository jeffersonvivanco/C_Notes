#include <stdio.h>

extern int val;

int val = 12;

int main() {
    printf("The number is %d\n", val);
    return 0;
}