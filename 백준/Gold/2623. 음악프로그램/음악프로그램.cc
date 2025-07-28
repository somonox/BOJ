#include<iostream>
#include<vector>
#include<queue>

using namespace std;

vector<vector<int>> graph;
vector<int> result;
int t[1001];
int num;
int sinum;
int i, j;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> num >> sinum;
    graph.resize(num + 1);

    for (i = 0; i < sinum; i++) {
        int inum;
        int prev = -1;
        cin >> inum;
        for (j = 0; j < inum; j++) {
            int tmp;
            cin >> tmp;
            if (prev == -1) {
                prev = tmp;
                continue;
            }
            t[tmp]++;
            graph[prev].push_back(tmp);
            prev = tmp;
        }
    }


    queue<int> q;
    for (int i = 1; i <= num; i++)
        if (t[i] == 0) q.push(i);

    while (!q.empty()) {
        int now = q.front();
        q.pop();
        result.push_back(now);

        for (int next : graph[now]) {
            t[next]--;
            if (t[next] == 0) q.push(next);
        }
    }

    if (result.size() != num)
        cout << 0 << "\n";
    else
        for (int x : result)
            cout << x << "\n";

    return 0;
}