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

int num;
int i;

int main() {
    FASTIO;
    DLOOP(i, 5) {
        int tmp;
        INPS(tmp);
        num += tmp;
    }

    OUTLNWV(num);

    return 0;
}