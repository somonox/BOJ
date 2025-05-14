#include<iostream>
#include<queue>
#include<map>

using namespace std;

queue<pair<long long, int>> q; // long long으로 바꾸는 게 안정적
map<long long, bool> ch;
long long a, b;

int main() {
    ios::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);

    cin >> a >> b;
    q.push({a, 1});
    while (!q.empty()) {
        long long fr = q.front().first;
        int cnt = q.front().second;
        q.pop();

        if (fr == b) {
            cout << cnt << endl;
            return 0;
        }

        if (ch.count(fr) > 0 || fr > b) continue;

        ch[fr] = true;
        q.push({fr * 2, cnt + 1});
        q.push({fr * 10 + 1, cnt + 1});
    }

    cout << -1 << endl;

    return 0;
}
