#include<iostream>
#include<vector>

using namespace std;

int n, r, q;
vector<vector<int>> graph;
int costs[100001];
int i;

void paternity_test(int cur, int parent) {
    costs[cur] = 1;
    for (int node : graph[cur]) {
        if (node != parent) {
            paternity_test(node, cur);
            costs[cur] += costs[node];
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> r >> q;
    graph.resize(n + 1);

    for (i = 0; i < n - 1; i++) {
        int t1, t2;
        cin >> t1 >> t2;

        graph[t1].push_back(t2);
        graph[t2].push_back(t1);
    }

    paternity_test(r, -1);

    for (i = 0; i < q; i++) {
        int query;
        cin >> query;
        cout << costs[query] << '\n';
    }

    return 0;
}