#include<iostream>
#include<vector>
#include<algorithm>
#define fastio ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0)

using namespace std;
using ll = unsigned long long;

vector<ll> v;
ll k, n;
ll i, j;

bool check(ll cut) {
    ll ans = 0;
    for (auto i : v)
        ans += (i / cut);
    return ans >= n;
}

int main () {
    fastio;
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif

    cin >> k >> n;

    for (i = 0; i < k; i++) {
        int tmp;
        cin >> tmp;
        v.push_back(tmp);
    }

    ll l = 1;
    ll r = *max_element(v.begin(), v.end());
    ll ans = 0;

    while (l <= r) {
        int mid = (l + r) / 2;
        if (check(mid)) {
            ans = mid;
            l = mid + 1;
        } else
            r = mid - 1;
    }

    cout << ans << endl;

    return 0;
}