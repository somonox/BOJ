#include<iostream>
#include<stack>

using namespace std;

int darai[1024][1024];
int x, y, sum;
int i, j;

int main() {
    cin >> x >> y;

    for (i = 0; i < y; i++) {
        int tmp1;
        cin >> tmp1;
        for (j = x - tmp1; j <= x; j++) {
            darai[j][i] = 1;
        }
    }

    for (i = 0; i < x; i++) {
        stack<int> s;
        for (j = 0; j < y; j++) {
            if (darai[i][j] == 1 && !s.empty()) {
                int val = s.top();
                s.pop();
                sum += j - val;
            }

            if (darai[i][j + 1] == 0 && darai[i][j] == 1)
                s.push(j + 1);
        }
    }
    cout << sum << endl;

    return 0;
}