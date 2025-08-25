#include <bits/stdc++.h>

using namespace std;


const int MAXN = 20;
const int FULL = 1 << MAXN;
const int INF = 1e9;

int num;
int D[MAXN][MAXN];
int dp[FULL];

int i, j;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> num;

    for (i = 0; i < num; i++)
        for (j = 0; j < num; j++)
            cin >> D[i][j];

    for (int i = 0; i < (1 << num); i++)
        dp[i] = INF;
    dp[0] = 0;

    for (int mask = 0; mask < (1 << num); mask++) {
        // k is number of people
        int k = __builtin_popcount(mask);
        for (int j = 0; j < num; j++) {
            if (mask & (1 << j))
                continue;
            int nxt = mask | (1 << j);
            dp[nxt] = min(dp[nxt], dp[mask] + D[k][j]);
        }
    }

    cout << dp[(1 << num) - 1];

    return 0;
}