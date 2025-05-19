#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

// z: 높이 (h), y: 행 (n), x: 열 (m)
struct coordinate {
    int z, y, x;
};

queue<coordinate> q;
int box[101][101][101]; // [h][n][m]
int m, n, h;
int dx[6] = {1, -1, 0, 0, 0, 0}; // x 방향 (가로)
int dy[6] = {0, 0, 1, -1, 0, 0}; // y 방향 (세로)
int dz[6] = {0, 0, 0, 0, 1, -1}; // z 방향 (높이)

void bfs() {
    while (!q.empty()) {
        int z = q.front().z;
        int y = q.front().y;
        int x = q.front().x;
        q.pop();
        for (int i = 0; i < 6; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            int nz = z + dz[i];
            if (nx < 0 || nx >= m || ny < 0 || ny >= n || nz < 0 || nz >= h)
                continue;
            if (box[nz][ny][nx] != 0)
                continue;
            box[nz][ny][nx] = box[z][y][x] + 1;
            q.push({nz, ny, nx});
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> m >> n >> h;

    for (int z = 0; z < h; z++) {
        for (int y = 0; y < n; y++) {
            for (int x = 0; x < m; x++) {
                cin >> box[z][y][x];
                if (box[z][y][x] == 1) {
                    q.push({z, y, x});
                }
            }
        }
    }

    bfs();

    int res = 0;
    for (int z = 0; z < h; z++) {
        for (int y = 0; y < n; y++) {
            for (int x = 0; x < m; x++) {
                if (box[z][y][x] == 0) {
                    cout << -1 << '\n';
                    return 0;
                }
                res = max(res, box[z][y][x]);
            }
        }
    }

    cout << res - 1 << '\n';
    return 0;
}
