#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector<int> v;
int dp[10242424];
int num;
int i, j;

int main() {
    cin >> num;

    for (i = 0; i < num; i++) {
        int tmp;
        cin >> tmp;
        v.push_back(tmp);
    }

    for (i = 0; i < num; i++) {
        for (j = i + 1; j < num; j++) {
            if (v[j] > v[i])
                dp[j] = max(dp[j], dp[i] + 1);
        }
    }

    cout << *max_element(dp, dp + num + 1) + 1 << endl;

    return 0;
}