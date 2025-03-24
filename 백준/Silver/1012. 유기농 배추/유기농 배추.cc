#include<iostream>
#include<queue>

using namespace std;

int hehe[4096][4096];
int tn;
int r, c, cn;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int i, j, ek;

int jirungee() {
    ek = 0;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (hehe[i][j] == 1) {
                ek++;
                queue<pair<int, int>> q;
                q.push({i, j});
                hehe[i][j] = 0;
                while (!q.empty()) {
                    pair<int, int> p = q.front();
                    q.pop();

                    for (int k = 0; k < 4; k++) {
                        if (hehe[p.first + dx[k]][p.second + dy[k]] == 1) {
                            hehe[p.first + dx[k]][p.second + dy[k]] = 0;
                            q.push({p.first + dx[k], p.second + dy[k]});
                        }
                    }
                }
            }
        }
    }

    return ek;
}

int main() {
    cin >> tn;

    for (i = 0; i < tn; i++) {
        cin >> r >> c >> cn;

        for (j = 0; j < cn; j++) {
            int tmp1, tmp2;
            scanf("%d%d", &tmp1, &tmp2);
            hehe[tmp1][tmp2] = 1;
        }
        printf("%d\n", jirungee());
    }

    return 0;
}