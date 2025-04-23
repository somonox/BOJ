#include<stdio.h>

int num;
int i, j;

int main() {
    scanf("%d", &num);
    for (i = 1; i <= 9; i++)
        printf("%d * %d = %d\n", num, i, num * i);

    return 0;
}