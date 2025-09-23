#include<bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define DLOOP(n, w) for (w = 0; w < n; w++)
#define RLOOP(n, k, w) for (w = n; w <= k; w++)
#define FILLV(v, k) v.resize(k); for (auto &i : v)
#define OUTV(v) for (auto &i : v)
#define PRINTLN(v) cout << v << endl
#define FINP freopen("input.txt", "r", stdin)

#define TL __int128_t
#define ULL unsigned long long
#define ll long long

using namespace std;

vector<int> v;
int num, ans, cnt, cnt2;
int i, j;

int main() {
    FASTIO;
    cin >> num;
    FILLV(v, num + 3)
        cin >> i;

    DLOOP(num, i) {
        if (v[i+1] > v[i + 2]) {
            cnt = min(v[i], v[i+1] - v[i+2]);
            ans += 5*cnt;

            v[i] -= cnt;
            v[i+1] -= cnt;

            cnt2 = min(v[i], min(v[i+1], v[i+2]));
            ans += 7*cnt2;

            v[i] -= cnt2;
            v[i+1] -= cnt2;
            v[i+2] -= cnt2;
        }else{
            cnt = min(v[i], min(v[i+1], v[i+2]));
            ans += 7 * cnt;

            v[i] -= cnt;
            v[i+1] -= cnt;
            v[i+2] -= cnt;

            cnt2 = min(v[i], v[i+1]);
            ans += 5*cnt2;

            v[i] -= cnt2;
            v[i+1] -= cnt2;
        }
        ans += 3*v[i];
        v[i] = 0;
    }

    PRINTLN(ans);

    return 0;
}