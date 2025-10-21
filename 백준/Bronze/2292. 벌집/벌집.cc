#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int n;

int main() {
    cin >> n;
    
    int ret = 1;
    int max = 1;
    int add = 6;

    while (1) {
        if (n <= max) 
          break;

        max += add;
        add += 6;
        ++ret;
    }

    printf("%d\n", ret);

    return 0;
}