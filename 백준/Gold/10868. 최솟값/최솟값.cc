#include<bits/stdc++.h>
#define INF 2'000'000'001LL

using namespace std;
using ll = long long;

vector<ll> tree, v;
ll n, m, k;
ll i, j;

void build(ll node, ll l, ll r, const vector<ll>& a) {
    if (l == r) {
        tree[node] = a[l];
        return;
    }
    ll m = (l + r) >> 1;
    build(node << 1, l, m, a);
    build(node << 1 | 1, m + 1, r, a);
    tree[node] = min(tree[node << 1], tree[node << 1 | 1]);
}

ll query(ll node, ll nl, ll nr, ll ql, ll qr) {
    if (qr < nl || nr < ql) return INF;
    if (ql <= nl && nr <= qr) return tree[node];
    ll m = (nl + nr) >> 1;
    return min(query(node << 1, nl, m, ql, qr), query(node << 1 | 1, m + 1, nr, ql, qr));
}

int main() {
    ios::sync_with_stdio(NULL);
    cin.tie(NULL);
    
    cin >> n >> m;
    tree.resize(n * 4, INF);

    for (i = 0; i < n; i++) {
        ll tmp;
        cin >> tmp;
        v.push_back(tmp);
    }

    build(1, 0, n - 1, v);

    for (i = 0; i < m; i++) {
        ll a, b;
        cin >> a >> b;
        if(a > b) swap(a, b);

        cout << query(1, 0, n - 1, --a, --b) << '\n';
    }


    return 0;
}