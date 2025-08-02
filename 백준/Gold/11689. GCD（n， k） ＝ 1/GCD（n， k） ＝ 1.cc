#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll n;
ll phi = n;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;

    phi = n;

    if (n % 2 == 0) {
        phi -= phi / 2;
        while (n % 2 == 0)
            n /= 2;
    }

    for (ll p = 3; p * p <= n; p += 2) {
        if (n % p == 0) {
            phi -= phi / p;
            while (n % p == 0)
                n /= p;
        }
    }

    if (n > 1)
        phi -= phi / n;

    cout << phi;
    
    return 0;
}
