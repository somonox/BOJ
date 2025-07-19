#include<iostream>

using namespace std;

int ddang[1025][1025];
int n, m, t;
int i, j;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;

    for (i = 1; i <= n; i++)
        for (j = 1; j <= m; j++) {
            cin >> ddang[i][j];
            ddang[i][j] += ddang[i - 1][j] + ddang[i][j - 1] - ddang[i - 1][j - 1];
        }

    cin >> t;
    for (i = 0; i < t; i++) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        cout << ddang[x2][y2] - ddang[x1 - 1][y2] - ddang[x2][y1 - 1] + ddang[x1 - 1][y1 - 1]  << '\n';
    }

    return 0;
}