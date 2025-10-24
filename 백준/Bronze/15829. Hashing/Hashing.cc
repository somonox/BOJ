#include<iostream>

using namespace std;

char a[100];
unsigned long long L, orr = 31, r = 1;
unsigned long long M = 1234567891;
unsigned long long sum = 0;
int i;

int main() {
    cin >> L;

    for (i = 0; i < L; i++)
        cin >> a[i];

    for (i = 0; i < L; i++) {
        sum += (a[i] - 'a' + 1) * r;
        r *= orr;
    }

    cout << sum % M << endl;

    return 0;
}