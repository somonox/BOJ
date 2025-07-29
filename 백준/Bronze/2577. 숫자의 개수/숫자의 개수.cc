#include<iostream>

using namespace std;

long long a, b, c, res;
int aa[10];

int main() {
    cin >> a >> b >> c;
    res = a * b * c;

    while (res != 0) {
        aa[res%10]++;
        res /= 10;
    }


    for (int i = 0; i < 10; i++) {
        cout << aa[i] << endl;
    }

    return 0;
}