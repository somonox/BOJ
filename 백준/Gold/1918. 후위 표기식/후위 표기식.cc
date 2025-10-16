#include<bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define DLOOP(w, n) for (w = 0; w < n; w++)
#define RLOOP(w, n, k) for (w = n; w <= k; w++)
#define LOOP while (true)
#define LOOPN(n) while(n--)
#define FILLV(v, k) v.resize(k); for (auto &i : v)
#define OUTRBL(v) for (auto &i : v)
#define FINP freopen("input.txt", "r", stdin)
#define INPS(n) cin >> n
#define OUTLNWV(v) cout << v << endl
#define OUTLN cout << endl
#define OUTV(v) cout << v << " "
#define OUTVWNS(v) cout << v
#define IFBRK(exprs) if (exprs) break

#define TL __int128_t
#define ULL unsigned long long
#define LL long long
using namespace std;

stack<char> stk;
char pri[256];
string str;

int main() {
    FASTIO;
    INPS(str);
    pri['+'] = pri['-'] = 1;
    pri['*'] = pri['/'] = 2;

    char prev = 0;
    OUTRBL(str) {
        if (isalpha(i) || isdigit(i)) {
            OUTVWNS(i);
        } else if (i == '(') {
            stk.push(i);
        } else if (i == ')') {
            while (!stk.empty() && stk.top() != '(') {
                OUTVWNS(stk.top());
                stk.pop();
            }
            stk.pop();
        } else {
            while (!stk.empty() && pri[stk.top()] >= pri[i]) {
                OUTVWNS(stk.top());
                stk.pop();
            }
            stk.push(i);
        }
    }

    while (!stk.empty()) {
        OUTVWNS(stk.top());
        stk.pop();
    }

    return 0;
}