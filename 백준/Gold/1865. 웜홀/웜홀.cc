#include<iostream>
#include<vector>
#define fastio ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define INF 1e9

using namespace std;

struct edge {
    int u;
    int v;
    int w;
};

bool bellman_ford(vector<edge> &edges, vector<int> &dist) {
    bool negc = false;
    for (int i = 1; i <= dist.size(); ++i) {
        for (auto [u, v, w] : edges) {
            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                if (i == dist.size()) return true;
            }
        }
    }

    return false;
}

int num;
int i, j, k;

int main () {
    fastio;
    cin >> num;

    for (i = 0; i < num; i++) {
        int a, b, c;
        vector<edge> edges;
        vector<int> dist;
        cin >> a >> b >> c;
        dist.assign(a + 1, 0);
        for (j = 0; j < b; j++) {
            int x, y, z;
            cin >> x >> y >> z;
            // Edge should be undirected
            edges.push_back({x, y, z});
            edges.push_back({y, x, z});
        }
        // Wormhole is edges that have negative weight
        for (j = 0; j < c; j++) {
            int x, y, z;
            cin >> x >> y >> z;
            edges.push_back({x, y, -z});
        }
        bool valid = bellman_ford(edges, dist);
        cout << (valid ? "YES" : "NO") << '\n';
    }

    return 0;
}