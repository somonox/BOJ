#include <iostream>
#include <queue>
#define fastio ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0)

using namespace std;

struct state {
    int x, y;
    int c;
    bool broke;
};

int map[1024][1024];
bool ch[1024][1024][2];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
int a, b;

int main() {
    fastio;
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    scanf("%d %d", &a, &b);

    for (int i = 0; i < a; i++)
        for (int j = 0; j < b; j++)
            scanf("%1d", &map[i][j]);

    queue<state> q;
    q.push({0, 0, 1, false});
    ch[0][0][0] = true;

    while (!q.empty()) {
        state s = q.front();
        q.pop();

        if (s.x == a - 1 && s.y == b - 1) {
            cout << s.c << '\n';
            return 0;
        }

        for (int i = 0; i < 4; i++) {
            int nx = s.x + dx[i];
            int ny = s.y + dy[i];

            if (nx < 0 || ny < 0 || nx >= a || ny >= b)
                continue;

            if (map[nx][ny] == 0 && !ch[nx][ny][s.broke]) {
                ch[nx][ny][s.broke] = true;
                q.push({nx, ny, s.c + 1, s.broke});
            }
            else if (map[nx][ny] == 1 && !s.broke && !ch[nx][ny][1]) {
                ch[nx][ny][1] = true;
                q.push({nx, ny, s.c + 1, true});
            }
        }
    }

    cout << -1 << '\n';
    return 0;
}
