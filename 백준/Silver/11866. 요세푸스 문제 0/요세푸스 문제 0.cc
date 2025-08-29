#include<iostream>
#include<queue>

using namespace std;

queue<int> q;
int n, k;
int i;

int main() {
    cin >> n >> k;

    for (i = 1; i <= n; i++) {
        q.push(i);
    }
    cout << "<";
    while (!q.empty()) {
        for (i = 0; i < k - 1; i++) {
            q.push(q.front());
            q.pop();
        }
        if (q.size() == 1) {
            cout << q.front();
            q.pop();
        }else {
            cout << q.front() << ", ";
            q.pop();
        }
    }
    cout << ">";

    return 0;
}