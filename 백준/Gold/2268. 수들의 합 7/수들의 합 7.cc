#include<bits/stdc++.h>

using namespace std;
using ll = long long;

vector<ll> tree;
int n, m;
int i, j;

void point_update(ll node, ll nl, ll nr, ll idx, ll val) {
    if (idx < nl | nr < idx) return;
    if (nr == nl) {
        tree[node] = val;
        return;
    }
    ll m = (nl + nr) >> 1;
    point_update(node << 1,nl, m, idx, val);
    point_update(node << 1 | 1, m + 1, nr, idx, val);
    tree[node] = (tree[node << 1] + tree[node << 1 | 1]);
}

ll query(ll node, ll nl, ll nr, ll ql, ll qr) {
    if (qr < nl || nr < ql) return 0;
    if (ql <= nl && nr <= qr) return tree[node];
    ll m = (nl + nr) >> 1;
    return (query(node << 1, nl, m, ql, qr) + query(node << 1 | 1, m + 1, nr, ql, qr));
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    tree.assign(n * 4, 0);

    for (i = 0; i < m; i++) {
        ll a, b, c;
        cin >> a >> b >> c;
        if (a == 0) {
            if (b > c) swap(b, c);
            cout << query(1, 1, n, b, c) << '\n';
        } else {
            point_update(1, 1, n, b, c);
        }
    }


    return 0;
}