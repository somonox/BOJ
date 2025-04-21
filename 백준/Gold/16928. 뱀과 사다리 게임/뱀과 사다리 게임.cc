#include<iostream>
#include<queue>

using namespace std;

int board[101];
int visited[101];
int n, m;

int find_minp() {
    queue<pair<int, int>> q;
    q.push({1, 0});
    visited[1] = true;

    while (!q.empty()) {
        pair<int, int> p = q.front();
        q.pop();

        if (p.first == 100)
            return p.second;

        for (int i = 1; i <= 6; i++) {
            int next = p.first + i;
            if (next > 100) continue;

            if (board[next] != 0)
                next = board[next];

            if (!visited[next]) {
                visited[next] = true;
                q.push({next, p.second + 1});
            }
        }
    }

    return -1;
}

int main() {
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        board[x] = y;
    }

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        board[u] = v;
    }

    cout << find_minp() << endl;

    return 0;
}
