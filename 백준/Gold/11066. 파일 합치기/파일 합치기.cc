#include<iostream>
#include<vector>
#include<climits>

using namespace std;

int solution(int num, vector<long long> v) {
    long long dp[501][501], ps[501];
    ps[0] = 0;
    for (int i = 1; i <= num; ++i)
        ps[i] = ps[i - 1] + v[i - 1];

    for (int i = 1; i <= num; ++i)
        dp[i][i] = 0;

    for (int i = 2; i <= num; ++i)
        for (int j = 1; j + i - 1 <= num; ++j) {
            int r = j + i - 1;
            long long minn = LLONG_MAX;

            for (int k = j; k < r; ++k)
                minn = min(minn, dp[j][k] + dp[k + 1][r] + ps[r] - ps[j - 1]);
            dp[j][r] = minn;
        }
    return dp[1][num];
}

int t, num;
int i;

int main() {
    cin >> t;

    while (t--) {
        cin >> num;
        vector<long long> v(num);
        for (auto &i : v)
            cin >> i;
        cout << solution(num, v) << endl;
    }

    return 0;
}