#include<iostream>

int a;

int main() {
    scanf("%d",&a);

    printf("%d", __builtin_popcount(a));

    return 0;
}