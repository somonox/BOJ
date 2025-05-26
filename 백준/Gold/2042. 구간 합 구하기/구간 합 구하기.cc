#include<iostream>
#include<vector>
#define fastio ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0)

using namespace std;
using ll = long long;

vector<ll> seg;
ll n, m, k, base = 1;
ll i, j;

ll rs(ll l, ll r) {
    l += base;
    r += base;
    ll res = 0;

    while (r >= l) {
        if (l % 2 == 1) res += seg[l++];
        if (r % 2 == 0) res += seg[r--];
        l /= 2;
        r /= 2;
    }
    return res;
}

void cn(ll index, ll value) {
    ll p = index + base;
    ll diff = value - seg[p];

    while (p >= 1) {
        seg[p] += diff;
        p /= 2;
    }
}

int main() {
    fastio;
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    cin >> n >> m >> k;

    while (base < n)
        base <<= 1;

    seg.resize(base * 2);

    for (i = base + 1; i <= base + n; i++)
        cin >> seg[i];


    for (i = base - 1; i >= 1; i--)
        seg[i] = seg[i * 2] + seg[i * 2 + 1];

    for (i = 0; i < m + k; i++) {
        ll a, b, c;
        cin >> a >> b >> c;
        if (a == 1)
            cn(b, c);
        else
            cout << rs(b, c) << '\n';
    }


    return 0;
}