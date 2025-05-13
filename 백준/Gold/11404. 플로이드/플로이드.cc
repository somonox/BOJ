#include<iostream>
#include<climits>

using namespace std;

int matrix[1024][1024];
int vertex, edge;
int i, j, k;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    fill(&matrix[0][0], &matrix[0][0] + 1024 * 1024, 10000000);
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

    for (i = 1; i <= vertex; i++) {
        for (j = 1; j <= vertex; j++) {
            if (matrix[i][j] == 10000000)
                cout << 0 << " ";
            else
                cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}