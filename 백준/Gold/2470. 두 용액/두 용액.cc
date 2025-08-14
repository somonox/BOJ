#include<iostream>
#include<algorithm>
#include<vector>
#define INF (long long)9e18

using namespace std;
using ll = long long;

vector<ll> v;
ll num;
long long mind = INF;
ll l, r, ml, mr;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> num;

    v.resize(num);

    for (auto &i : v) {
        cin >> i;
    }

    sort(v.begin(), v.end());
    r = v.size() - 1;

    while (l < r) {
        if (llabs(v[r] + v[l]) < mind) {
            ml = l;
            mr = r;
            mind = llabs(v[r] + v[l]);
        }

        if (llabs(v[r] + v[l + 1]) < llabs(v[r - 1] + v[l])) {
            l++;
        } else {
            r--;
        }
    }

    cout << v[ml] << ' ' << v[mr] << endl;

    return 0;
}