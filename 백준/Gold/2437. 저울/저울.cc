#include<iostream>
#include<algorithm>
#include<vector>
#define fastio ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0)

using namespace std;
using ll = long long;

vector<ll> v;
ll num, target = 1;
ll i;

int main() {
    fastio;
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    cin >> num;

    for (i = 0; i < num; i++) {
        int a;
        cin >> a;
        v.push_back(a);
    }
    sort(v.begin(), v.end());

    for (i = 0; i < v.size(); i++) {
        if (v[i] > target)
            break;
        target += v[i];
    }

    cout << target << endl;

    return 0;
}