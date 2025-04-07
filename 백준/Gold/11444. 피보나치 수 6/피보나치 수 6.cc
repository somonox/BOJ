#include<iostream>
#include<vector>
using namespace std;

// Litteraly coding WARCRIME ngl

vector<vector<unsigned long long >> multiply(const vector<vector<unsigned long long >>& a, const vector<vector<unsigned long long >>& b) {
    vector<vector<unsigned long long >> res(2, vector<unsigned long long >(2));
    res[0][0] = (a[0][0]*b[0][0] + a[0][1]*b[1][0]) % 1000000007;
    res[0][1] = (a[0][0]*b[0][1] + a[0][1]*b[1][1]) % 1000000007;
    res[1][0] = (a[1][0]*b[0][0] + a[1][1]*b[1][0]) % 1000000007;
    res[1][1] = (a[1][0]*b[0][1] + a[1][1]*b[1][1]) % 1000000007;
    return res;
}

vector<vector<unsigned long long >> power(vector<vector<unsigned long long >> baise, unsigned long long jisu) {
    vector<vector<unsigned long long >> result = {{1, 0}, {0, 1}};

    while (jisu > 0) {
        if (jisu % 2 == 1)
            result = multiply(result, baise);
            baise = multiply(baise, baise);
        jisu /= 2;
    }

    return result;
}

unsigned long long fib(unsigned long long  n) {
    if (n == 0) return 0;
    vector<vector<unsigned long long >> fibb = {{1, 1}, {1, 0}};
    vector<vector<unsigned long long >> res = power(fibb, n - 1);
    return res[0][0];
}

int main() {
    unsigned long long  n;
    cin >> n;

    cout << fib(n) << endl;
    return 0;
}
