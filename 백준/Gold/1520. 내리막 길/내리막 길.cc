#include<iostream>
#define fastio ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0)

using namespace std;

int m, n;
int map[1024][1024], ch[1024][1024];
int dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};

int search(int x, int y) {
    int sum = 0;

    if (x == m - 1 && y == n - 1)
        return 1;
    if (ch[x][y] != -1) return ch[x][y];

    ch[x][y] = 0;
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i], ny = y + dy[i];
        if (nx >= 0 && nx < m && ny >= 0 && ny < n && map[nx][ny] < map[x][y])
            ch[x][y] += search(nx, ny);
    }

    return ch[x][y];
}

int main() {
    fastio;
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    cin >> m >> n;

    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            cin >> map[i][j];

    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            ch[i][j] = -1;

    cout << search(0, 0) << endl;

    return 0;
}