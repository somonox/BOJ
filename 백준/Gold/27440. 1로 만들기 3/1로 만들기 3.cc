#include<iostream>
#include<queue>
#include<unordered_map>

using namespace std;
using ull = unsigned long long;

ull num;

int makeone() {
    queue<pair<ull, int>> q;
    unordered_map<ull, int> mp;
    q.push({num, 0});

    while (!q.empty()) {
        ull curr = q.front().first;
        int cnt = q.front().second;
        q.pop();

        if (curr == 1)
            return cnt;

        if (curr % 3 == 0 && mp.find(curr / 3) == mp.end()) {
            q.push({curr / 3, cnt + 1});
            mp[curr / 3] = cnt + 1;
        }
        if (curr % 2 == 0 && mp.find(curr / 2) == mp.end()) {
            q.push({curr / 2, cnt + 1});
            mp[curr / 2] = cnt + 1;
        }
        if (mp.find(curr - 1) == mp.end()) {
            q.push({curr - 1, cnt + 1});
            mp[curr - 1] = cnt + 1;
        }
    }
}


int main() {
    cin >> num;
    cout << makeone();

    return 0;
}