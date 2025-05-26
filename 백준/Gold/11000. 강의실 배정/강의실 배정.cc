#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

#define fastio ios_base::sync_with_stdio(0);cin.tie(0);

using namespace std;

vector<pair<int, int>> v;
priority_queue<int, vector<int>, greater<int>> q;
int num;
int i;

int main() {
    fastio;
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif

    cin >> num;

    for (i = 0; i < num; i++) {
        int a, b;
        cin >> a >> b;
        v.push_back({a, b});
    }

    sort(v.begin(), v.end());

    q.push(v[0].second);

    for (i = 1; i < v.size(); i++) {
        if (v[i].first >= q.top())
            q.pop();
        q.push(v[i].second);
    }

    cout << q.size() << endl;

    return 0;
}