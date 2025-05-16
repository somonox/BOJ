#include<iostream>
#include<queue>
#include<cstring>

using namespace std;

int num;
int ch[1024][1024];
int dxx[8] = {-2, -1,  1,  2,  2,  1, -1, -2};
int dyy[8] = {1,  2,  2,  1, -1, -2, -2, -1};

struct node {
    int x;
    int y;
    int c;
};

int path(int sx, int sy, int dx, int dy, int chess) {
    queue<node> q;

    q.push({sx, sy, 0});
    ch[sx][sy] = 1;

    while (!q.empty()) {
        int x = q.front().x;
        int y = q.front().y;
        int c = q.front().c;
        q.pop();

        if (x == dx && y == dy) {
            return c;
        }

        for (int i = 0; i < 8; i++) {
            int nx = x + dxx[i];
            int ny = y + dyy[i];

            if (nx >= chess || ny >= chess || nx < 0 || ny < 0 || ch[nx][ny] == 1)
                continue;

            ch[nx][ny] = 1;
            q.push({nx, ny, c + 1});
        }
    }
}

int main() {
    cin >> num;

    for (int i = 1; i <= num; i++) {
        int sx, sy, ex, ey, chess;
        cin >> chess;
        cin >> sx >> sy >> ex >> ey;
        cout << path(sx, sy, ex, ey, chess) << endl;
        memset(ch, 0, sizeof(ch));
    }

    return 0;
}