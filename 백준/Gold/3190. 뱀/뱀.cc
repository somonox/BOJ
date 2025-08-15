#include<iostream>
#include<deque>

using namespace std;

deque<pair<int, int>> q;
int board[101][101];
deque<pair<int, int>> snake;
int n, k, l;
int i, j, second;
int dir_idx = 1;
int dy[4] = {0, 1, 0, -1};
int dx[4] = {1, 0, -1, 0};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    board[1][1] = -1;
    snake.push_back(make_pair(1, 1));

    cin >> n;
    cin >> k;
    for (i = 0; i < k; i++) {
        int ax, ay;
        cin >> ax >> ay;
        board[ax][ay] = 1;
    }

    cin >> l;
    for (i = 0; i < l; i++) {
        int second;
        char rotate;
        cin >> second >> rotate;
        q.push_back(make_pair(second, rotate));
    }

    while (true) {
        second++;
        int nx = snake.back().first + dx[dir_idx];
        int ny = snake.back().second + dy[dir_idx];

        if(nx <= 0 || nx > n || ny <= 0 || ny > n || board[nx][ny] == -1)
            break;

        if(board[nx][ny] != 1){
            board[snake.front().first][snake.front().second] = 0;
            snake.pop_front();
        }

        board[nx][ny] = -1;
        snake.push_back({nx, ny});

        if (!q.empty() && second == q.front().first) {
            if(q.front().second == 'D')
                dir_idx = (dir_idx + 3) % 4;
            else dir_idx = (dir_idx + 1) % 4;
            q.pop_front();
        }
    }

    cout << second;

    return 0;
}