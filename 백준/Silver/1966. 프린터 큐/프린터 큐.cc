#include<iostream>
#include<queue>
using namespace std;

int num;
int i, j;

int main() {
    cin >> num;

    for (i = 0; i < num; i++) {
        int n, m;
        cin >> n >> m;
        queue<pair<int, int>> q;
        priority_queue<int> pq;
        int cnt = 0;

        for (j = 0; j < n; j++) {
            int tmp;
            cin >> tmp;
            q.push({tmp, j});
            pq.push(tmp);

        }
        while (true) {
            while (q.front().first < pq.top()) {
                q.push(q.front());
                q.pop();
            }
            if (q.front().second == m) {
                cout << cnt + 1 << '\n';
                break;
            }
            pq.pop();
            q.pop();
            cnt++;
        }

    }

    return 0;
}