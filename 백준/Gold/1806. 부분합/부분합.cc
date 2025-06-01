#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
#define fastio ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0)

using namespace std;

vector<int> v;
int n, s, m = INT_MAX;
int i;

int main() {
    fastio;
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    cin >> n >> s;

    int tmp;
    cin >> tmp;
    v.push_back(0);
    v.push_back(tmp);

    for (i = 2; i <= n; i++) {
        int tmp;
        cin >> tmp;
        v.push_back(tmp + v.at(i - 1));
    }

    int p1 = 0, p2 = 1;

    while (p2 < v.size()) {
        if (v.at(p2) - v.at(p1) < s)
            p2++;
        else {
            p1++;
            m = min(m, p2 - p1);
        }
    }

    if (m == INT_MAX)
        cout << 0 << endl;
    else
        cout << m + 1 << endl;



    return 0;
}