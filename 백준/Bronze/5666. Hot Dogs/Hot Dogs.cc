#include<iostream>
#include<iomanip>

using namespace std;

double a, b;

int main() {
    while (cin >> a >> b)
        cout << fixed << setprecision(2) << a / b << endl;

    return 0;
}