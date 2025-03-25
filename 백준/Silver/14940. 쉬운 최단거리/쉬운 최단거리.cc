#include<iostream>
#include<queue>

using namespace std;

int mao[1024][1024];
int ch[1024][1024];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int num1, num2;
int tx, ty;
int i, j;

int main() {
    cin >> num1 >> num2;

    for (i = 0; i < num1; i++) {
        for (j = 0; j < num2; j++) {
            cin >> mao[i][j];
            if (mao[i][j] == 2){
                tx = i;
                ty = j;
            }
        }
    }
    queue<pair<int, int>> q;
    q.push({tx, ty});

    mao[tx][ty] = 0;
    ch[tx][ty] = 1;

    while (!q.empty()) {
        int xp = q.front().first;
        int xy = q.front().second;
        q.pop();

        for (i = 0; i < 4; i++) {
            int nx = xp + dx[i];
            int ny = xy + dy[i];

            if (ch[nx][ny] == 1 || mao[nx][ny] == 0 || nx < 0 || ny < 0 || nx >= num1 || ny >= num2)
                continue;

            ch[nx][ny] = 1;
            mao[nx][ny] = mao[xp][xy] + 1;
            q.push({nx, ny});
        }

    }

    for (i = 0; i < num1; i++) {
        for (j = 0; j < num2; j++) {
            if (ch[i][j] == 0 && mao[i][j] != 0) {
                cout << -1 << " ";
                continue;
            }
            cout << mao[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}