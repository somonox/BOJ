#include<iostream>
#include<vector>

using namespace std;

vector<vector<int>> graph;
int dp[100001];
int n, w;
int i;

void dfs(int n) {
    for (int i : graph[n]) {
        dp[i] += dp[n];
        dfs(i);
    }
}

void print_state() {
    for (int i = 1; i <= n; i++) {
        cout << dp[i] << " ";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> w;
    graph.resize(n + 1);

    for (i = 0; i < n; i++) {
        int tmp;
        cin >> tmp;
        if (tmp == -1)
            continue;
        graph[tmp].push_back(i + 1);
    }

    for (i = 0; i < w; i++) {
        // Employee number, Praise number
        int en, pn;
        cin >> en >> pn;
        dp[en] += pn;
    }

    dfs(1);

    print_state();

    return 0;
}