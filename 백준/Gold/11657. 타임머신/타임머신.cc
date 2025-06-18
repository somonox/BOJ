#include <iostream>
#include <vector>
#include <tuple>
#include <limits>
using namespace std;

const long long INF = 1e18;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;

    vector<tuple<int, int, int>> edges;
    for (int i = 0; i < M; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        edges.emplace_back(a, b, c);
    }

    vector<long long> dist(N + 1, INF);
    dist[1] = 0;

    bool negc = false;

    for (int i = 1; i <= N; ++i) {
        for (auto [u, v, w] : edges) {
            if (dist[u] != INF && dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                if (i == N) negc = true;
            }
        }
    }

    if (negc) {
        cout << -1 << '\n';
    } else {
        for (int i = 2; i <= N; ++i) {
            if (dist[i] == INF)
                cout << -1 << '\n';
            else
                cout << dist[i] << '\n';
        }
    }

    return 0;
}
