#include<iostream>
#include<algorithm>
#include<vector>
#include<climits>
#include<stack>

using namespace std;

vector<pair<int, int>> d;
int num;
int i;

int main() {
    cin >> num;
    d.resize(num + 1);
    d[num].first = 0;
    d[num].second = num;

    for (i = 0; i < num; i++) {
        d[i].first = INT_MAX;
        d[i].second = -1;
    }

    for (i = num; i >= 0; i--) {
        if (d[i].first != INT_MAX) {
            if (i % 3 == 0 && d[i / 3].first > d[i].first + 1) {
                d[i / 3].first = d[i].first + 1;
                d[i / 3].second = i;
            }
            if (i % 2 == 0 && d[i / 2].first > d[i].first + 1) {
                d[i / 2].first = d[i].first + 1;
                d[i / 2].second = i;
            }
            if (i - 1 > 0 && d[i - 1].first > d[i].first + 1) {
                d[i - 1].first = d[i].first + 1;
                d[i - 1].second = i;
            }
        }
    }

    cout << d[1].first << endl;

    i = 1;
    stack<int> s;
    while (i != d[i].second) {
        s.push(i);
        i = d[i].second;
    }
    cout << num << " ";
    while (!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }

    return 0;
}