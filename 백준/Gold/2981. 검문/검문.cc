#include<iostream>
#include<vector>
#include<numeric>
#include<algorithm>

using namespace std;
using ll = long long;

vector<ll> v;
ll num;
ll pivot;
ll i;

ll gcd_sequence(vector<ll> vv) {
    ll res = vv[0];
    for (ll i = 1; i < vv.size(); ++i)
        res = gcd(res, vv[i]);

    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> num;
    cin >> pivot;

    v.resize(num - 1);
    for (auto &i : v) {
        cin >> i;
        i -= pivot;
    }

    ll mid_res = gcd_sequence(v);

    vector<ll> ans;
    for (ll i = 2; i * i <= mid_res; ++i)
        if (mid_res % i == 0) {
            ans.push_back(i); 
            ans.push_back(mid_res / i);
        }
    ans.push_back(mid_res);

    sort(ans.begin(), ans.end());
    ans.erase(unique(ans.begin(), ans.end()), ans.end());

    for (auto x : ans)
        cout << x << ' ';

    return 0;
}