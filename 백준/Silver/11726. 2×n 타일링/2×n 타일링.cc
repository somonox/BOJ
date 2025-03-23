#include<iostream>

using namespace std;

long long a = 1, b = 1;
int num;
int i;

int main () {
    cin >> num;

    for (i = 0; i < num; i++) {
        long long tmp;
        tmp = a;
        a = b;
        b = (b + tmp) % 10007;
    }   

    cout << a << endl;

    return 0;
}
