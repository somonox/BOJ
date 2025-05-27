#include<iostream>
#define fastio ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0)

using namespace std;
using ll = long long;

ll s[2001];
bool dp[2001][2001];
ll num, qnum;
ll i, j, k;

int main() {
    fastio;
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    cin >> num;

    for (i = 1; i <= num; i++) {
        cin >> s[i];
    }

    for (i = 1; i <= num; i++)
        dp[i][i] = 1;

    for (i = 1; i <= num; i++)
        dp[i][i + 1] = s[i] == s[i+1];

    for (int i = 3; i <= num; i++) {
        for (int j = 1; j + i - 1 <= num; j++) {
            int e = j + i - 1;
            dp[j][e] = (s[j] == s[e] && dp[j+1][e-1]);
        }
    }

    cin >> qnum;

    for (i = 1; i <= qnum; i++) {
        int s, e;
        cin >> s >> e;
        cout << dp[s][e] << '\n';
    }


    return 0;
}