#include<iostream>
#include<vector>

using namespace std;

vector<vector<pair<int, int>>> tree;
vector<bool> visited;
int n, m;
int i;

int dfs(int nn, int mok, int cnt) {
    if (nn == mok) {
        return cnt;
    }
    visited[nn] = true;

    for (pair<int, int> socks : tree[nn]) {
        if (visited[socks.first])
            continue;
        int res = dfs(socks.first, mok, cnt + socks.second);
        if (res != -1)
            return res;
    }
    return -1;
}

int main() {
    cin >> n >> m;
    tree.resize(n + 1);
    visited.resize(n + 1);
    for (i = 0; i < n - 1; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        tree[a].push_back(make_pair(b, c));
        tree[b].push_back(make_pair(a, c));
    }

    for (i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        cout << dfs(a, b, 0) << "\n";
        fill(visited.begin(), visited.end(), false);
    }


    return 0;
}