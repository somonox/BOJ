#include<iostream>

using namespace std;

unsigned long long suhang;
unsigned long long num;
unsigned long long i, j;
int dp[102402038];

int main() {
    cin >> suhang;
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 4;

    for (i = 0; i < suhang; i++) {
        cin >> num;
        for (j = 4; j <= num; j++) {
            if (dp[j] != 0)
                continue;
            dp[j] = dp[j - 1] + dp[j - 2] + dp[j - 3];
        }

        cout << dp[num] << endl;
    }

    return 0;
}

