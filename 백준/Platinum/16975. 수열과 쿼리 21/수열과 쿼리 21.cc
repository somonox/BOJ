#include <bits/stdc++.h>

using namespace std;
using ll = long long;

vector<ll> tree;
int m;
int num;

ll sum(int i) {
    ll res = 0;
    while (i > 0) {
        res += tree[i];
        i -= i & -i;
    }
    return res;
}

void update(int i, ll diff) {
    while (i < tree.size()) {
        tree[i] += diff;
        i += i & -i;
    }
}

void rangeUpdate(int i, int j, ll diff) {
    update(i, diff);
    update(j+1, -diff);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> num;
    tree.resize(num + 1);
    for (int i = 1; i <= num; i++) {
        ll cur;
        cin >> cur;
        rangeUpdate(i, i, cur);
    }

    cin >> m;
    while (m--) {
        int op, a, b, c;
        cin >> op;
        switch (op) {
            case 1:
                cin >> a >> b >> c;
            rangeUpdate(a, b, c);
            break;
            case 2:
                cin >> a;
            cout << sum(a) << '\n';
            break;
        }
    }


    return 0;
}