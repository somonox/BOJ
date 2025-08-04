#include<iostream>
#include<queue>
#include<unordered_map>
#include<vector>
#include<algorithm>

using namespace std;
using ull = unsigned long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    ull l, n, k;
    cin >> l >> n >> k;

    unordered_map<ull, ull> visited;
    queue<ull> q;
    vector<ull> results;

    for (ull i = 0; i < n; i++) {
        ull tmp;
        cin >> tmp;
        if (!visited.count(tmp)) {
            q.push(tmp);
            visited[tmp] = 0;
            results.push_back(0);
        }
    }

    while (!q.empty() && results.size() < k) {
        ull curr = q.front();
        q.pop();

        if (curr > 0) {
            ull next = curr - 1;
            if (!visited.count(next)) {
                visited[next] = visited[curr] + 1;
                q.push(next);
                results.push_back(visited[next]);
            }
        }

        if (curr < l) {
            ull next = curr + 1;
            if (!visited.count(next)) {
                visited[next] = visited[curr] + 1;
                q.push(next);
                results.push_back(visited[next]);
            }
        }
    }

    sort(results.begin(), results.end());

    for (ull i = 0; i < k && i < results.size(); i++) {
        cout << results[i] << "\n";
    }

    return 0;
}