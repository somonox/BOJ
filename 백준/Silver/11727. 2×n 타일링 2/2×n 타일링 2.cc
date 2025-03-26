#include<iostream>

using namespace std;

int num;
int dp[1024];
int i;

int main() {
    cin >> num;
    dp[1] = 1;
    dp[2] = 3;
    dp[3] = 5;

    for (i = 4; i <= num; i++) {
        dp[i] = (dp[i - 1] + dp[i - 2] * 2) % 10007;
    }

    cout << dp[num] << endl;

    return 0;
}