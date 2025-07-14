#include <bits/stdc++.h>
using namespace std;

vector<int> l;
vector<long long> dp;
long long cnt = 0;
int n;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    l.resize(n);
    for (auto &i : l)
        cin >> i;
    dp.resize(n);

    for (int i = 1; i < n; ++i) {
        double base = ceil(log2((double)l[i - 1] / l[i]));
        long long r = (long long)base + dp[i - 1];
        if (r > 0) {
            dp[i] = r;
            cnt += r;
        }
    }

    cout << cnt;
    return 0;
}
