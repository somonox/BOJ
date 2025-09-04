#include<bits/stdc++.h>

using namespace std;

int num;

int f_d(int a) {
    a = (a * 2) % 10000;
    return a;
}
int f_s(int a) {
    a--;
    if (a < 0)
        a = 9999;
    return a;
}
int f_l(int a) {
    a = (a * 10) % 10000 + (a * 10) / 10000;
    return a;
}
int f_r(int a) {
    a = (a / 10) + (a % 10) * 1000;
    return a;
}

string hehe(int a, int b) {
    int visited[10000];
    memset(visited, 0, sizeof(visited));
    queue<pair<int, string>> q;
    q.push(make_pair(a, ""));
    while (!q.empty()) {
        pair<int, string> p = q.front();
        q.pop();
        if (p.first == b) {
            return p.second;
        }

        if (visited[f_d(p.first)] == 0) {
            q.push({f_d(p.first), p.second + 'D'});
            visited[f_d(p.first)] = 1;
        }
        if (visited[f_s(p.first)] == 0) {
            q.push({f_s(p.first), p.second + 'S'});
            visited[f_s(p.first)] = 1;
        }
        if (visited[f_l(p.first)] == 0) {
            q.push({f_l(p.first), p.second + 'L'});
            visited[f_l(p.first)] = 1;
        }
        if (visited[f_r(p.first)] == 0) {
            q.push({f_r(p.first), p.second + 'R'});
            visited[f_r(p.first)] = 1;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> num;

    while (num--) {
        int a, b;
        cin >> a >> b;
        cout << hehe(a, b) << '\n';
    }

    return 0;
}