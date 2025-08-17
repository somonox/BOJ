#include <bits/stdc++.h>

using namespace std;

vector<int> parent;
vector<char> visited;
int num, t;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);


    cin >> t;

    while (t--) {
        cin >> num;
        parent.resize(num + 1);
        visited.resize(num + 1);
        for (int i = 0; i < num - 1; ++i) {
            int a, b;
            cin >> a >> b;
            parent[b] = a;
        }
        int u, v;
        cin >> u >> v;

        vector<char> visited(num + 1, 0);
        while (u) {
            visited[u] = 1;
            u = parent[u];
        }
        while (!visited[v])
            v = parent[v];
        cout << v << '\n';
        parent.clear();
        visited.clear();
    }
    return 0;
}
