#include<iostream>
#include<queue>

using namespace std;

priority_queue<int> pq;
int m[1024][1024];
int ch[1024][1024];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
int num;
int i, j;

int main() {
    cin >> num;

    for (int i = 0; i < num; i++)
        for(int j = 0; j < num; j++)
            scanf("%1d", &m[i][j]);

    for (i = 0; i < num; i++) {

        for (j = 0; j < num; j++) {
            queue<pair<int, int>> q;
            if (m[i][j] == 1 && ch[i][j] == 0) {
                int cnt = 0;
                q.push({i, j});
                ch[i][j] = 1;
                while(!q.empty()) {
                    int x = q.front().first;
                    int y = q.front().second;
                    q.pop();

                    for (int k = 0; k < 4; k++) {
                        int nx = x + dx[k];
                        int ny = y + dy[k];

                        if (m[nx][ny] == 1 && ch[nx][ny] == 0) {
                            q.push({nx, ny});
                            ch[nx][ny] = 1;
                            cnt++;
                        }
                    }
                }
                pq.push(-cnt);
            }
        }
    }

    cout << pq.size() << endl;
    int a = pq.size();
    for (i = 0; i < a; i++) {
        cout << -pq.top() + 1 << endl;
        pq.pop();
    }

    return 0;
}