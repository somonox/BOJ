#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

int M, N, K;
int map[101][101];
bool visited[101][101];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int dfs(int x, int y) {
    map[x][y] = 1;
    int sum = 1;

    for (int k = 0; k < 4; k++) {
        int nx = x + dx[k];
        int ny = y + dy[k];

        if (nx < 0 || nx >= M || ny < 0 || ny >= N || map[nx][ny] == 1)
            continue;

        sum += dfs(nx, ny);
    }
    return sum;
}

int main() {
    cin >> M >> N >> K;

    for (int i = 0; i < K; i++) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;

        // 좌표계를 맵 배열에 맞게 바꿔서 직사각형 영역 채우기
        for (int y = y1; y < y2; y++) {
            for (int x = x1; x < x2; x++) {
                map[y][x] = 1;
            }
        }
    }

    vector<int> v;

    for (int i = 0; i < M; i++) {
        for (int y = 0; y < N; y++) {
            if (map[i][y] == 0 && visited[i][y] == 0) {
                v.push_back(dfs(i, y));
            }
        }
    }

    sort(v.begin(), v.end());

    cout << v.size() << endl;
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }

    return 0;
}
