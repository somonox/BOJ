#include<bits/stdc++.h>

using namespace std;

vector<int> vertexValue;
long long adj_matrix[100][100];
int n, m, r, res;
int i, j, k;

int main() {
    cin >> n >> m >> r;
    vertexValue.resize(n);
    for (auto &i : vertexValue)
        cin >> i;

    for (i = 0; i < 100; i++)
        for (j = 0; j < 100; j++)
            adj_matrix[i][j] = INT_MAX;

    for (i = 0; i < 100; i++)
        adj_matrix[i][i] = 0;

    for (i = 0; i < r; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        u--;
        v--;

        adj_matrix[u][v] = w;
        adj_matrix[v][u] = w;
    }

    for (k = 0; k < n; k++)
        for (i = 0; i < n; i++)
            for (j = 0; j < n; j++)
                adj_matrix[i][j] = min(adj_matrix[i][j], adj_matrix[i][k] + adj_matrix[k][j]);

    for (i = 0; i < n; i++) {
        int maybe_sum = 0;
        for (j = 0; j < n; j++) {
            if (adj_matrix[i][j] <= m) {
                maybe_sum += vertexValue[j];
            }
        }
        res = max(res, maybe_sum);
    }

    cout << res << endl;

    return 0;
}