#include<iostream>

using namespace std;

unsigned long long ps[1030][1030];
unsigned long long as[1030][1030];
unsigned long long rc, qnum;
unsigned long long i, j;

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> rc >> qnum;

    for (i = 0; i < rc; i++)
        for (j = 0; j < rc; j++)
            cin >> ps[i][j];

    for (i = 0; i < rc; i++)
        for (j = 0; j < rc; j++)
            as[i][j] = ps[i][j] + as[i - 1][j] + as[i][j - 1] - as[i - 1][j - 1];

    for (i = 0; i < qnum; i++) {
        unsigned long long x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        x1--;
        y1--;
        x2--;
        y2--;
        cout << as[x2][y2] - as[x1 - 1][y2] - as[x2][y1 - 1] + as[x1 - 1][y1 - 1] << "\n";
    }

    return 0;
}