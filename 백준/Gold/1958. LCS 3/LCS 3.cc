#include<iostream>
#include<cstring>

using namespace std;

char a[101] = {0}, b[101] = {0}, c[101] = {0};
int ab[101][101][101];
int i, j, k;

int main() {
    scanf("%s", a);
    scanf("%s", b);
    scanf("%s", c);

    for (i = 1; i <= strlen(a); i++) {
        for (j = 1; j <= strlen(b); j++) {
            for (k = 1; k <= strlen(c); k++) {
                if (a[i - 1] == b[j - 1] && b[j - 1]  == c[k - 1])
                    ab[i][j][k] = ab[i - 1][j - 1][k - 1] + 1;
                else
                    ab[i][j][k] = max(ab[i - 1][j][k], max(ab[i][j - 1][k], ab[i][j][k - 1]));
            }
        }
    }

    cout << ab[strlen(a)][strlen(b)][strlen(c)] << endl;;


    return 0;
}