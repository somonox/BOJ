#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
using ll = long long;

vector<ll> v;
vector<ll> unions;
vector<ll> complement;
ll num, pc, unionsum, complementsum;
ll i, j;

int main() {
    cin >> pc >> num;
    v.resize(pc);

    for (auto &i : v) {
        cin >> i;
        unions.push_back(num / i);
    }

    for (ll mask = 1; mask < (1 << pc); ++mask) {
        if (__builtin_popcount((unsigned)mask) < 2)
            continue;
        vector<ll> comb;
        for (ll i = 0; i < pc; ++i)
            if (mask >> i & 1)
                comb.push_back(v[i]);
        ll sum = 1;
        for (ll i = 0; i < comb.size(); ++i) {
            sum *= comb[i];
        }
        if (comb.size() % 2 == 0)
            sum = -sum;
        complement.push_back(num / sum);
    }

    for (auto i :unions) {
        unionsum += i;
    }

    for (auto j : complement) {
        complementsum += j;
    }

    cout << unionsum + complementsum << endl;


    return 0;
}