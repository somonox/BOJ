#include<iostream>
#include<queue>

using namespace std;

priority_queue<int, vector<int>, greater<>> pq;
int num, sum;
int i, j;

int main() {
    cin >> num;

    for (i = 0; i < num; i++) {
        int tmp;
        cin >> tmp;
        pq.push(tmp);
    }

    while (pq.size() != 1) {
        int top = pq.top();
        pq.pop();
        int second = pq.top();
        pq.pop();
        sum += top + second;
        pq.push(top + second);
    }

    cout << sum << endl;;



    return 0;
}