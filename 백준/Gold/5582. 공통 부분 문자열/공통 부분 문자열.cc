#include<iostream>

using namespace std;

int dp[4001][4001], maxy;
string a, b;
int i, j;

int main() {
    cin >> a >> b;

    for (i = 1; i <= a.length(); i++) {
        for (j = 1; j <= b.length(); j++) {
            if (a[i - 1] == b[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
        }
    }

    for (i = 0; i <= a.length(); i++) {
        for (j = 0; j <= b.length(); j++) {
            maxy = max(maxy, dp[i][j]);
        }
    }

    cout << maxy << endl;

    return 0;
}