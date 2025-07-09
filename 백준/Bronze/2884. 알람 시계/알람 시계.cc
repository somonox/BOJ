#include<iostream>

using namespace std;

int n1, n2;

int main() {
    cin >> n1 >> n2;
    n2 -= 45;
    if (n2 < 0) {
        n1--;
        n2 += 60;
    }
    if (n1 < 0)
        n1 += 24;

    cout << n1 << " " << n2;

    return 0;
}