#include<bits/stdc++.h>

#define fastio ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define DLOOP(w, n) for (w = 0; w < n; w++)
#define RLOOP(w, n, k) for (w = n; w <= k; w++)
#define FILLV(v, k) v.resize(k); for (auto &i : v)
#define OUTV(v) for (auto &i : v)
#define FINP freopen("input.txt", "r", stdin)
#define INPS(n) cin >> n
#define OUTLNWV(v) cout << v << endl
#define OUTLN cout << endl
#define OUTV(v) cout << v << " "

#define TL __int128_t
#define ULL unsigned long long
#define ll long long
using namespace std;

int a[1024][1024];
int n, m;
int i, j;

int main() {
    fastio;
    INPS(n);
    INPS(m);
    
    DLOOP(i, n)
        DLOOP(j, m) {
            INPS(a[i][j]);
        }
    
    DLOOP(i, n) {
        DLOOP(j, m) {
            int tmp;
            INPS(tmp);
            OUTV(tmp + a[i][j]);
        }
        OUTLN;
    }

    return 0;
} 