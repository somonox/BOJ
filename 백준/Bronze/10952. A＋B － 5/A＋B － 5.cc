#include<iostream>

using namespace std;

int a, b;

int main() {
    while(true) {
        cin >> a >> b;
        if (a == b && a == 0)
            break;
        cout << a + b << '\n';
    }
    return 0;
}