#include<iostream>

using namespace std;

int n, m, p;
int i, j, k;
long long amat[1024][1024];
long long bmat[1024][1024];
int resmat[1024][1024];

int main() {
    cin >> n >> m;

    for (i = 0; i < n; i++)
        for (j = 0; j < m; j++)
            cin >> amat[i][j];

    cin >> m >> p;

    for (i = 0; i < m; i++)
        for (j = 0; j < p; j++)
            cin >> bmat[i][j];

    for (int i = 0; i < n; ++i)
        for (int k = 0; k < m; ++k)
            for (int j = 0; j < p; ++j)
                resmat[i][j] += amat[i][k] * bmat[k][j];

    for (i = 0; i < n; i++) {
        for (j = 0; j < p; j++) {
            cout << resmat[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}