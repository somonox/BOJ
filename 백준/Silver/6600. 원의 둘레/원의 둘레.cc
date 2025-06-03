#include <iostream>
#include <cmath>
#include <iomanip>
#define PI 3.141592653589793
#define fastio ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0)

using namespace std;

double x1, yo, x2, y2, x3, y3;

int main() {
    fastio;
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif

    while (cin >> x1 >> yo >> x2 >> y2 >> x3 >> y3) {
        double fa = hypot(x2 - x3, y2 - y3);
        double fb = hypot(x1 - x3, yo - y3);
        double fc = hypot(x1 - x2, yo - y2);

        double area2 = fabs((x2 - x1) * (y3 - yo) - (x3 - x1) * (y2 - yo));

        double R = fa*fb*fc / (2.0 * area2);

        double C = 2.0 * PI * R;
        printf("%.2lf\n", C);
    }

    return 0;
}