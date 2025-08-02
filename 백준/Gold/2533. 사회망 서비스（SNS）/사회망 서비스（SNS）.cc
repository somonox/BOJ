#include<iostream>
#include<queue>

using namespace std;

vector<vector<int>> graph;
int dp[1000001][2], visited[1000001];
int num, cnt;
int i;

void dfs(int u) {
    visited[u] = 1;
    dp[u][0] = 0;
    dp[u][1] = 1;
    for (int v : graph[u]) if (!visited[v]) {
        dfs(v);
        dp[u][0] += dp[v][1];
        dp[u][1] += min(dp[v][0], dp[v][1]);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> num;
    graph.resize(num + 1);

    for (i = 0; i < num - 1; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    dfs(1);

    cout << min(dp[1][0], dp[1][1]) << '\n';


    return 0;
}