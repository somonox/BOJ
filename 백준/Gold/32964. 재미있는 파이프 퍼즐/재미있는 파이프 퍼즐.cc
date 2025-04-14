#include<iostream>

using namespace std;

char pipe[2][200001];
int ch[2][200001];
int num;
bool flag = false;
int i, j;

void graph(int x, int y, bool dir) {
    if (x < 0 || x >= 2 || y < 0 || y >= num) return;

    if (x == 1 && y == num - 1) {
        flag = true;
        return;
    }

    if (ch[x][y] == 1)
        return;
    ch[x][y] = 1;

    if (pipe[x][y] == 'X') {
        graph(x + 1, y, false);
        graph(x, y + 1, true);
    }

    if (pipe[x][y] == 'L') {
        if (dir) {
            graph(x + 1, y, false);
            graph(x - 1, y, false);
        } else {
            graph(x, y - 1, true);
            graph(x, y + 1, true);
        }
    }

    if (pipe[x][y] == 'I') {
        if (dir)
            graph(x, y + 1, true);
        else
            graph(x + 1, y, false);
    }
}


int main() {

    cin >> num;

    for (i = 0; i < 2; i++) {
        for (j = 0; j < num; j++) {
            cin >> pipe[i][j];
        }
    }

    graph(0, 0, false);

    if (flag)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;

    return 0;
}