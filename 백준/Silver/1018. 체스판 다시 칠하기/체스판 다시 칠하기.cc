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

int a, b;
char board[51][51];
int i, j, k, l;

// true: W
// false: B
int checks(bool ddong, int sx, int sy) {
    bool ys = ddong;
    int cnt = 0;
    RLOOP(k, sx, sx + 7) {
        RLOOP(l, sy, sy + 7) {
            // OUTV((board[k][l] == 'W'));
            // OUTV(ys);
            // OUTLNWV(((board[k][l] == 'W') ^ ys));
            if (((board[k][l] == 'W') ^ ys))
                cnt++;
            ys ^= 1;
        }
        ys ^= 1;
    }

    //OUTLN;

    return cnt;
}

int main() {
    FASTIO;
    INPS(a);
    INPS(b);

    DLOOP(i, a)
        INPS(board[i]);

    int mini = INT_MAX;

    DLOOP(i, a - 7) {
        DLOOP(j, b - 7) {
            mini = min(mini,min(checks(true, i, j), checks(false, i, j)));
        }
    }
    cout << mini;

    return 0;
}