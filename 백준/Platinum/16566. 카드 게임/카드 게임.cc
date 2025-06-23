#include<iostream>
#include<algorithm>
#include <numeric>
#include<vector>
#define fastio ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)

using namespace std;

vector<int> card, parent;
int n, m, k;
int i, j;

int find(int v) {
    if (v == parent[v])
        return v;
    else
        return parent[v] = find(parent[v]);
}

void use(int x) {
    parent[x]=find(x + 1);
}

int main() {
    fastio;
    cin >> n >> m >> k;

    for (i = 0; i < m; i++) {
        int tmp;
        cin >> tmp;
        card.push_back(tmp);
    }
    parent.resize(card.size() + 1);
    iota(parent.begin(), parent.end(), 0);
    sort(card.begin(), card.end());

    for (i = 0; i < k; i++) {
        int tmp;
        cin >> tmp;
        int idx = upper_bound(card.begin(), card.end(), tmp) - card.begin();
        idx = find(idx);
        cout << card[idx] << "\n";
        use(idx);
    }
    return 0;
}