#include<iostream>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

using namespace std;

int cnt[10001];
int num, maxn;
int i, j;

int main() {
    fastio;

    cin >> num;

    for (i = 0; i < num; i++) {
        int tmp;
        cin >> tmp;
        cnt[tmp]++;
        maxn = max(maxn, tmp);
    }

    for (i = 1; i <= maxn; i++) {
        for (j = 0; j < cnt[i]; j++)
            cout << i << '\n';
    }


    return 0;
}