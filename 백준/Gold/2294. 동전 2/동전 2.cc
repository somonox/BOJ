#include<iostream>
#include<climits>

using namespace std;

long long coin[100002], dp[1000000];
int n, k;
int i;

int main() {
    cin >> n >> k;
    fill(dp, dp + 1000000, INT_MAX);

    for (i = 0; i < n; i++)
        cin >> coin[i];

    dp[k] = 0;

    for (i = k; i >= 0; i--) {
        for (int j = 0; j < n; j++) {
            if (i - coin[j] >= 0 && dp[i] != INT_MAX)
                dp[i - coin[j]] = min(dp[i - coin[j]],  dp[i] + 1);
        }
    }
    if (dp[0] == INT_MAX)
        cout << -1 << endl;
    else
        cout << dp[0] << endl;

    return 0;
}