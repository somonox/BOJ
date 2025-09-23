#include<bits/stdc++.h>

#define fastio ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define DLOOP(n, w) for (w = 0; w < n; w++)
#define RLOOP(n, k, w) for (w = n; w <= k; w++)
#define FILLV(v, k) v.resize(k); for (auto &i : v)
#define OUTV(v) for (auto &i : v)
#define FINP freopen("input.txt", "r", stdin)
#define INPS(n) cin >> n
#define OUTLN(v) cout << v << endl

#define TL __int128_t
#define ULL unsigned long long
#define ll long long

using namespace std;

string tmp;
int num;
int i;

int main() {
    INPS(num);

    DLOOP(num, i) {
        INPS(tmp);
        transform(tmp.begin(), tmp.end(), tmp.begin(), ::tolower);
        OUTLN(tmp);
    }

    return 0;
}