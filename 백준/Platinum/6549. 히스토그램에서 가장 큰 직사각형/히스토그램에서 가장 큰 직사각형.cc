#include <bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define FINP freopen("input.txt", "r", stdin)
#define INPS(n) cin >> n
#define OUTLNWV(v) cout << v << '\n'
#define IFBRK(exprs) if (exprs) break
#define ULL unsigned long long
using namespace std;

int main() {
    FASTIO;
#ifndef ONLINE_JUDGE
    FINP;
#endif

    while (true) {
        int n;
        INPS(n);
        IFBRK(n == 0);

        vector<ULL> h(n);
        for (int i = 0; i < n; i++) INPS(h[i]);

        stack<pair<ULL, ULL>> s;
        ULL maxy = 0;

        for (int i = 0; i < n; i++) {
            ULL start = i;

            while (!s.empty() && s.top().first > h[i]) {
                ULL height = s.top().first;
                ULL index = s.top().second;
                s.pop();
                ULL width = i - index;
                maxy = max(maxy, height * width);
                start = index;
            }

            s.push({h[i], start});
        }

        while (!s.empty()) {
            ULL height = s.top().first;
            ULL index = s.top().second;
            s.pop();
            ULL width = n - index;
            maxy = max(maxy, height * width);
        }

        OUTLNWV(maxy);
    }

    return 0;
}
