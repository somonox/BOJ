#include<iostream>
#include<vector>
#include<queue>
#include<climits>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

using namespace std;

int t;
int i;

int main() {
    fastio;
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif

    cin >> t;
    for (i = 0; i < t; i++) {
        int v, e;
        cin >> v >> e;

        vector<int> buildings(v + 1);
        vector<int> indegrees(v + 1);
        vector<vector<int>> adj(v + 1);

        for (int j = 1; j <= v; j++)
            cin >> buildings[j];

        for (int j = 0; j < e; j++) {
            int x, y;
            cin >> x >> y;
            indegrees[y] += 1;
            adj[x].push_back(y);
        }

        int mbb;
        cin >> mbb;

        queue<int> q;
        vector<long long> dp(v + 1);

        for (int ii = 1; ii < indegrees.size(); ii++)
            if (indegrees[ii] == 0) {
                q.push(ii);
                dp[ii] = buildings[ii];
            }
        int tt = 0;
        while (!q.empty()) {
            tt = q.front(); q.pop();
            for (int j = 0; j < adj[tt].size(); j++) {
                dp[adj[tt][j]] = max(dp[adj[tt][j]], dp[tt] + buildings[adj[tt][j]]);
                if (--indegrees[adj[tt][j]] == 0)
                    q.push(adj[tt][j]);
            }
        }

        cout << dp[mbb] << '\n';
    }



    return 0;
}