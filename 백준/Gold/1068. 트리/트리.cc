#include<iostream>
#include<vector>

using namespace std;

vector<vector<int>> graph;
vector<int> parent, dead;
int num, cnt, dv, root = -1;
int i;

void dfs(int v) {
    if (dead[v]) return;
    dead[v] = 1;
    for (int nv : graph[v])
        dfs(nv);
}

void count(int v) {
    if (dead[v]) return;
    int child = 0;
    for (int nv : graph[v]) {
        if (dead[nv]) continue;
        count(nv);
        child++;
    }
    if (child == 0)
        cnt++;
}

int main() {
    cin >> num;
    graph.resize(num);
    parent.resize(num);
    dead.assign(num, 0);

    for (i = 0; i < num; i++) {
        int a; cin >> a;
        parent[i] = a;
        if (a == -1)
            root = i;
        else
            graph[a].push_back(i);
    }

    cin >> dv;

    dfs(dv);
    count(root);

    cout << cnt << endl;
    return 0;
}
