#include<iostream>

using namespace std;

double A[1024][1024];
double L[1024][1024];
double U[1024][1024];

int num;
int i, j;

int main() {
    cin >> num;
    for (i = 0; i < num; i++) {
        for (j = 0; j < num; j++)
            scanf("%lf", &A[i][j]);
        L[i][i] = 1;
    }

    if (num == 1) {
        printf("-1\n");
        return 0;
    }

    U[0][0] = A[0][0];
    U[0][1] = A[0][1];

    for (i = 1; i < num; i++) {
        if (U[i - 1][i - 1] == 0) {
            printf("-1\n");
            return 0;
        }
        L[i][i - 1] = A[i][i - 1] / U[i - 1][i - 1];
        U[i][i] = A[i][i] - L[i][i - 1] * U[i - 1][i];
        if (i < num - 1)
            U[i][i + 1] = A[i][i + 1];
    }

    for (i = 0; i < num; i++) {
        for (j = 0; j < num; j++)
            printf("%.3lf ", L[i][j]);
        cout << '\n';
    }

    for (i = 0; i < num; i++) {
        for (j = 0; j < num; j++)
            printf("%.3lf ", U[i][j]);
        cout << '\n';
    }

    return 0;
}