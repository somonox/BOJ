#include<bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define DLOOP(w, n) for (w = 0; w < n; w++)
#define RLOOP(w, n, k) for (w = n; w <= k; w++)
#define LOOP while (true)
#define LOOPN(n) while(n--)
#define FILLV(v, k) v.resize(k); for (auto &i : v)
#define OUTV(v) for (auto &i : v)
#define FINP freopen("input.txt", "r", stdin)
#define INPS(n) cin >> n
#define OUTLNWV(v) cout << v << endl
#define OUTLN cout << endl
#define OUTV(v) cout << v << " "
#define IFBRK(exprs) if (exprs) break

#define TL __int128_t
#define ULL unsigned long long
#define LL long long
using namespace std;

vector<vector<pair<int, int>>> v;
int visited[10001];
int ddong;
int a;
int i;

// second gonna be answer
// First: accumulated length
// Second: max diameter

int dfs(int node) {
    visited[node] = 1;
    int f = 0, s = 0;

    for (auto [ss, b] : v[node]) {
        if (visited[ss]) continue;
        int cost = dfs(ss) + b;
        if (cost > f) {
            s = f;
            f = cost;
        }else if (cost > s)
            s = cost;
    }

    ddong = max(ddong, f + s);
    return f;
}

int main() {
    FASTIO;
    INPS(a);
    v.resize(a + 1);

    DLOOP(i, a - 1) {
        int a, b, w;
        cin >> a >> b >> w;
        v[a].push_back(make_pair(b, w));
        v[b].push_back(make_pair(a, w));
    }

    dfs(1);

    OUTV(ddong);

    return 0;
}