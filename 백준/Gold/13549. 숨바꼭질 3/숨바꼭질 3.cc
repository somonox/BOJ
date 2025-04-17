#include<iostream>
#include<deque>
#include<climits>

using namespace std;

deque<pair<int, int>> q;
int di[1000001];
int n, m;

void find_least() {
    di[n] = 0;

    q.push_front({0, n});

    while (!q.empty()) {
        int curr = q.front().second;
        int cdist = q.front().first;
        q.pop_front();

        if (curr * 2 <= 100001 && cdist < di[curr * 2]) {
            di[curr * 2] = cdist;
            q.push_front({cdist, curr * 2});
        }
        if (curr + 1 <= m && cdist + 1 < di[curr + 1]) {
            di[curr + 1] = cdist + 1;
            q.push_back({cdist + 1, curr + 1});
        }
        if (curr - 1 >= 0 && cdist + 1 < di[curr - 1]) {
            di[curr - 1] = cdist + 1;
            q.push_back({cdist + 1, curr - 1});
        }
    }
}

int main() {
    cin >> n >> m;
    fill_n(di, 1000001, INT_MAX);

    find_least();
    cout << di[m] << endl;

    return 0;
}