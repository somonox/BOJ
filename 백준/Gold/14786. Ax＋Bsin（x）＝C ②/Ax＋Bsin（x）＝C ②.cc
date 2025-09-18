#include<iostream>
#include<cmath>
#include <iomanip>

using namespace std;

double a, b, c;
double start, ending, mid;

double eva(double x) {
    return (a * x + sin(x) * b) - c;
}

int main() {
    cin >> a >> b >> c;
    start = 0;
    ending = c * 2;
    mid = c;

    while (abs(start-ending) > 0.0000000001) {
        mid = (start + ending) / 2;

        if (eva(mid) <= 0)
            start = mid;
        else
            ending = mid;
        mid = (start + ending) / 2;
    }

    cout << fixed << setprecision(10) << mid << endl;

    return 0;
}