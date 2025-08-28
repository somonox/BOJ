#include<bits/stdc++.h>

using namespace std;
using ll = long long;

vector<set<ll>> v;
ll n, q;
ll i, j;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> q;
    v.resize(n + 1);
    for (i = 1; i <= n; i++) {
        ll k;
        cin >> k;
        for (ll j = 0; j < k; j++) {
            int tmp;
            cin >> tmp;
            v[i].insert(tmp);
        }
    }

    for (i = 0; i < q; i++) {
        int x, y, z;
        cin >> x;
        cin >> y;
        if (x == 1) {
            cin >> z;
            if (v[y].size() < v[z].size())
                swap(v[y], v[z]);
            for (auto& i : v[z])
                v[y].insert(i);
            v[z].clear();

        } else{
            cout << v[y].size() << '\n';
        }
    }

    return 0;
}