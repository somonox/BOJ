#include<iostream>
#include<climits>
#include <numeric>

using namespace std;

int a, b;
int k, min_s = INT_MAX, x, y;
int i;

int main() {
    cin >> a >> b;

    k = b / a;

    for (i = 1; i * i <= k; i++) {
        if (k % i == 0) {
            int m = i;
            int n = k / m;

            if (gcd(m, n) == 1) {
                int tx = a * m;
                int ty = a * n;

                if (tx + ty < min_s) {
                    min_s = tx + ty;
                    x = tx;
                    y = ty;
                }
            }
        }
    }

    cout << x << " " << y << endl;

    return 0;
}