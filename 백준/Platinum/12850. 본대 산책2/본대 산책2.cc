#include<iostream>

using namespace std;

long long num;
long long M = 1000000007;

__int128 __res[8][8];

__int128 matrix[8][8] = {
    {0, 1, 1, 0, 0, 0, 0, 0},
    {1, 0, 1, 1, 0, 0, 0, 0},
    {1, 1, 0, 1, 1, 0, 0, 0},
    {0, 1, 1, 0, 1, 1, 0, 0},
    {0, 0, 1, 1, 0, 1, 1, 0},
    {0, 0, 0, 1, 1, 0, 0, 1},
    {0, 0, 0, 0, 1, 0, 0, 1},
    {0, 0, 0, 0, 0, 1, 1, 0}
};

void copy(__int128 from[8][8], __int128 to[8][8]) {
    for (int i = 0; i < 8; i++)
        for (int j = 0; j < 8; j++)
            to[i][j] = from[i][j];
}

void mulmat(__int128 a[8][8], __int128 b[8][8], __int128 res[8][8]) {
    for (int i = 0; i < 8; i++)
        for (int j = 0; j < 8; j++) {
            res[i][j] = 0;
            for (int k = 0; k < 8; k++) {
                res[i][j] += a[i][k] * b[k][j];
                res[i][j] %= M;
            }
        }
}

void idmat(__int128 res[8][8]) {
    for (int i = 0; i < 8; i++)
        for (int j = 0; j < 8; j++)
            res[i][j] = (i == j);
}

void power(__int128 a[8][8], long long exp, __int128 res[8][8]) {
    __int128 base[8][8], tmp[8][8];
    idmat(res);
    copy(a, base);
    while (exp > 0) {
        if (exp & 1) {
            mulmat(res, base, tmp);
            copy(tmp, res);
        }
        mulmat(base, base, tmp);
        copy(tmp, base);
        exp >>= 1;
    }
}

int main() {
    cin >> num;
    power(matrix, num, __res);
    cout << (long long)__res[0][0] << endl;

    return 0;
}