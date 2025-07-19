#include<iostream>
#include<climits>

using namespace std;

int ddang[301][301];
int num, maxx = INT_MIN;
int i, j, k;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>num;

    for (i = 1; i <= num; i++)
        for (j = 1; j <= num; j++) {
            cin>>ddang[i][j];
            ddang[i][j] += ddang[i][j-1] + ddang[i-1][j] - ddang[i-1][j-1];
        }

    for (int i = 1; i <= num; ++i)
        for (int j = 1; j + i - 1 <= num; ++j)
            for (int k = 1; k + i - 1 <= num; ++k) {
                int s = ddang[j+i-1][k+i-1] - ddang[j-1][k+i-1] - ddang[j+i-1][k-1] + ddang[j-1][k-1];
                maxx = max(maxx, s);
            }

    cout << maxx << endl;

    return 0;
}