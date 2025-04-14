#include <iostream>
#include <queue>
#include <vector>

using namespace std;

vector<vector<int>> graph(999999);
int t[999999];
int n, m;
int i, j;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> n >> m;

    for (i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        t[b]++;
        graph[a].push_back(b);
    }

    queue<int> q;

    for (i = 1; i <= n; i++) {
        if(t[i] == 0)
            q.push(i);
    }

    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        cout << cur << " ";

        for (int next : graph[cur]) {
            t[next]--;
            if (t[next] == 0)
                q.push(next);
        }
    }
    cout << endl;

    return 0;
}