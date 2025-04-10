#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>

using namespace std;

int v, e;
int start_node;
vector<vector<pair<int, int>>> graph;
int dp[2000000];

void dijkstra(int start) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    dp[start] = 0;
    pq.push({0, start});

    while (!pq.empty()) {
        int current_dist = pq.top().first;
        int current = pq.top().second;
        pq.pop();

        if (dp[current] < current_dist) continue;

        for (auto [next, weight] : graph[current]) {
            int next_dist = current_dist + weight;
            if (next_dist < dp[next]) {
                dp[next] = next_dist;
                pq.push({next_dist, next});
            }
        }
    }
}

int main() {
    cin >> v >> e >> start_node;
    graph.resize(v + 1);
    fill_n(dp, 2000000, INT_MAX);

    for (int i = 0; i < e; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({v, w});
    }

    dijkstra(start_node);

    for (int i = 1; i <= v; i++) {
        if (dp[i] == INT_MAX)
            cout << "INF ";
        else
            cout << dp[i] << " ";
    }

    return 0;
}
