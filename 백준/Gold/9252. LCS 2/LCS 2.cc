#include<iostream>
#include<algorithm>

using namespace std;

string a, b, res;
int dp[1001][1001];
int i, j;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> a >> b;

    for (i = 1; i <= a.length(); i++)
        for (j = 1; j <= b.length(); j++)
            if (a[i - 1] == b[j - 1])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);

    while (i > 0 && j > 0) {
        if (a[i - 1] == b[j - 1]) {
            res += a[i - 1];
            i--;
            j--;
        } else if (dp[i - 1][j] > dp[i][j - 1]) {
            i--;
        } else {
            j--;
        }
    }

    reverse(res.begin(), res.end());
    res.pop_back();

    cout << res.size() << endl;
    cout << res << endl;

    return 0;
}