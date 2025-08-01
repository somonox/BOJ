#include<iostream>
#include<stack>

using namespace std;

stack<int> s;
int k, sum;
int i;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> k;

    for (i = 0; i < k; i++) {
        int tmp;
        cin >> tmp;
        if (tmp == 0)
            s.pop();
        else
            s.push(tmp);
    }

    while (!s.empty()) {
        sum += s.top();
        s.pop();
    }

    cout << sum << endl;

    return 0;
}