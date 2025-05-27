#include<iostream>
#include<vector>
#define fastio ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0)

using namespace std;
using ll = long long;

ll dp[100001];
ll n, k;
ll i, j;

int main() {
    fastio;
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    cin >> n >> k;
    for (i = 0; i < n; i++) {
        int w, v;
        cin >> w >> v;
        for (j = k; j >= w; j--)
            dp[j] = max(dp[j], dp[j - w] + v);
    }

    cout << dp[k] << endl;

    return 0;
}