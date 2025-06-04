#include<iostream>
#include<vector>
#define fastio ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);

using namespace std;

int dp[3000001];
int num;
int i;

int main() {
    fastio;
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    cin >> num;

    for (i = 0; i <= num; i++) {
        dp[i] = max(dp[i], dp[i-1]);
        int t, p;
        cin >> t >> p;
        dp[i + t] = max(dp[i + t], dp[i] + p);
    }

    cout << dp[num] << endl;

    return 0;
}