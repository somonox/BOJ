#include<iostream>
#include<climits>
#include<vector>
#include<numeric>
#define INF 1e9

using namespace std;

int matrix[1024][1024];
int vertex, edge;
int i, j, k;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    fill(&matrix[0][0], &matrix[0][0] + 1024 * 1024, INF);
    cin >> vertex >> edge;

    for (i = 1; i <= edge; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        matrix[u][v] = min(matrix[u][v], w);
    }

    for (i = 1; i <= vertex; i++)
        matrix[i][i] = 0;

    for (k = 1; k <= vertex; k++) {
        for (i = 1; i <= vertex; i++) {
            for (j = 1; j <= vertex; j++) {
                matrix[i][j] = min(matrix[i][j], matrix[i][k] + matrix[k][j]);
            }
        }
    }

    int res = INF;
    for (i = 1; i <= vertex; i++) {
        for (j = 1; j <= vertex; j++) {
            // main diagonal should be 0 so result is not valid
            if (i == j) continue;
            // if not valid path is INF
            res = min(res, matrix[i][j] + matrix[j][i]);
        }
    }

    if (res == INF)
        cout << -1;
    else
        cout << res;

    return 0;
}