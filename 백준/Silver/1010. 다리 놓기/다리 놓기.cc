#include<iostream>

using namespace std;

int dp[31][31];

unsigned long long nCr(long long n, long long r) {
    for(int i=0;i<=n;i++){
        for(int j=0; j<=r;j++){
            if(i==j || j==0)
                dp[i][j] = 1;
            else
                dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
        }
    }
    return dp[n][r];
}

int num;
int i;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    cin >> num;

    for (i = 0; i < num; i++) {
        unsigned long long r, n;
        cin >> r >> n;
        cout << nCr(n, r) << '\n';
    }

    return 0;
}