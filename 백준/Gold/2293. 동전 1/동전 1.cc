#include<iostream>
#define fastio ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0)

using namespace std;
using ll = long long;
int n, k;
int dp[100001];
int i, j;

int main() {
    fastio;
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    cin >> n >> k;

    dp[0] = 1;

    for (int i = 0; i < n; i++) {
        int coin;
        cin >> coin;

        for (int j = coin; j <= k; j++)
            dp[j] += dp[j - coin];
    }

    cout << dp[k] << endl;

    return 0;
}