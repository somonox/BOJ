#include<iostream>
#include<queue>

using namespace std;

queue<int> q;
int num;
int i;

int main() {
    cin >> num;

    for (i = 1; i <= num; i++)
        q.push(i);

    while (q.size() != 1) {
        q.pop();
        q.push(q.front());
        q.pop();
    }

    cout << q.front() << endl;

    return 0;
}