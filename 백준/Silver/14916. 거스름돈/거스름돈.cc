#include<iostream>
#include<climits>

using namespace std;

int dp[1000001];
int num;
int i;

int main() {
    cin >> num;
    fill_n(dp, 100001, INT_MAX);

    dp[num] = 0;

    for (i = num; i >= 0; i--) {
        if (dp[i] != INT_MAX) {
            if (i - 5 >= 0)
                dp[i - 5] = min(dp[i - 5], dp[i] + 1);
            if (i - 2 >= 0)
                dp[i - 2] = min(dp[i - 2], dp[i] + 1);
        }
    }
    if (dp[0] == INT_MAX)
        cout << -1;
    else
        cout << dp[0];

    return 0;
}