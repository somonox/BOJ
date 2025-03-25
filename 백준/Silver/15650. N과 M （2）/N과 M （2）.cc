#include<iostream>
#include<vector>

using namespace std;

vector<int> v;
int n, m;

void backtrace(int start, int dehpt) {

    if (dehpt == m) {
        for (int i = 0; i < m; i++)
            printf("%d ", v[i]);
        printf("\n");
    }

    for (int i = start; i <= n; i++) {
        v.push_back(i);
        backtrace(i + 1, dehpt + 1);
        v.pop_back();
    }
}

int main() {
    cin >> n >> m;
    backtrace(1, 0);

    return 0;
}