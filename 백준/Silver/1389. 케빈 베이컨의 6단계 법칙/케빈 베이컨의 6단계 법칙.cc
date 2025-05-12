#include<iostream>
#include<vector>
#include<queue>
#include<climits>

using namespace std;

vector<vector<int>> vv;
int v, e, min_kevin_idx = INT_MAX, min_kevin_num = INT_MAX;
int i;

int kevin_bacon(int i) {
    int kevin = 0;
    int users[100];
    int visited[100];
    fill(users, users + 100, 9999999);
    fill(visited, visited + 100, 0);
    queue<pair<int, int>> q;
    q.push({i, 0});

    while (!q.empty()) {
        int fr = q.front().first;
        int fr12 = q.front().second;
        q.pop();
        users[fr] = min(users[fr], fr12);

        for (auto i : vv[fr]) {
            if (visited[i] == 0) {
                q.push({i, fr12 + 1});
                visited[i] = 1;
            }
        }
    }

    for (int j = 1; j <= v; j++) {
        if (users[i] == 9999999)
            continue;
        kevin += users[j];
    }

    return kevin;
}

int main() {
    cin >> v >> e;
    vv.resize(v + 1);

    for (i = 0; i < e; i++) {
        int a, b;
        cin >> a >> b;

        vv[a].push_back(b);
        vv[b].push_back(a);
    }

    for (i = 1; i <= v; i++) {
        int curr_kevin = kevin_bacon(i);
        if (curr_kevin <= min_kevin_num) {
            if (curr_kevin == min_kevin_num)
                min_kevin_idx = min(min_kevin_idx, i);
            else
                min_kevin_idx = i;
            min_kevin_num = min(curr_kevin, min_kevin_num);
        }
    }

    cout << min_kevin_idx << endl;

    return 0;
}