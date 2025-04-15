#include<iostream>

using namespace std;

unsigned long long a, b, c;
unsigned long long dap;
int i;

unsigned long long recursive_pow(unsigned long long a, unsigned long long b, unsigned long long c) {
    if (b == 0) return 1;
    if (b == 1) return a % c;

    unsigned long long half = recursive_pow(a, b / 2, c);
    unsigned long long result = (half * half) % c;

    if (b % 2 == 1)
        result = (result * a) % c;

    return result;
}

int main() {
    cin >> a >> b >> c;

    cout << recursive_pow(a, b, c) << endl;


    return 0;
}