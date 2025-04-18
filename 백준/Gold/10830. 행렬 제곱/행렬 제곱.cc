#include<iostream>
#include<vector>
using namespace std;

int n;
long long b;
vector<vector<int>> origin;

vector<vector<int>> mul_mat(const vector<vector<int>> &a, const vector<vector<int>> &b) {
    vector<vector<int>> result(n, vector<int>(n, 0));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                result[i][j] += (a[i][k] * b[k][j]) % 1000;
            }
            result[i][j] %= 1000;
        }
    }

    return result;
}

vector<vector<int>> pow_mat(long long exp) {
    if (exp == 1) {
        vector<vector<int>> base = origin;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                base[i][j] %= 1000;
        return base;
    }

    vector<vector<int>> half = pow_mat(exp / 2);
    vector<vector<int>> temp = mul_mat(half, half);

    if (exp % 2 == 1)
        return mul_mat(temp, origin);
    else
        return temp;
}

int main() {
    cin >> n >> b;
    origin.resize(n, vector<int>(n));

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> origin[i][j];

    vector<vector<int>> result = pow_mat(b);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            cout << result[i][j] << " ";
        cout << "\n";
    }

    return 0;
}
