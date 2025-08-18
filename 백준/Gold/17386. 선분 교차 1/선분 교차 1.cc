#include<bits/stdc++.h>

using namespace std;

using ll = long long;

pair<ll, ll> xx1, xx2, yy1, yy2;

ll get_ccw(pair<ll, ll> x, pair<ll, ll> y, pair<ll, ll> z) {
    ll res = 0;

    res += (x.first * y.second + y.first * z.second + z.first * x.second) - (x.second * y.first + y.second * z.first + z.second * x.first);
    if (res > 0)
        return 1;
    else if (res == 0)
        return 0;
    else
        return -1;
}

int main() {
    cin >> xx1.first >> xx1.second >> xx2.first >> xx2.second;
    cin >> yy1.first >> yy1.second >> yy2.first >> yy2.second;

    int x = get_ccw(xx1, xx2, yy1) * get_ccw(xx1, xx2, yy2);
    int y = get_ccw(yy1, yy2, xx1) * get_ccw(yy1, yy2, xx2);

    cout << (x <= 0 && y <= 0) << endl;

    return 0;
}