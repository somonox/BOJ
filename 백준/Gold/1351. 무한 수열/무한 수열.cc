#include<iostream>
#include<cassert>
#include<unordered_map>

using namespace std;
using ull = unsigned long long;

unordered_map<ull, ull> dp;
ull n, p, q;

void recursive_find(ull in, ull ip, ull iq) {
    assert(ip != 0 && iq != 0);
    if (in == 0) return;
    ull ipoin = in / ip;
    ull iqoin = in / iq;
    ull pv = 0, qv = 0;

    if (dp.count(ipoin) == 0)
        recursive_find(ipoin, ip, iq);
    if (dp.count(iqoin) == 0)
        recursive_find(iqoin, ip, iq);

    pv = dp[ipoin];
    qv = dp[iqoin];

    dp[in] = pv + qv;
}

int main() {
    cin >> n >> p >> q;
    dp[0] = 1;

    if (n == 0) {
        cout << 1 << endl;
        return 0;
    }

    recursive_find(n, p, q);

    cout << dp[n] << endl;

    return 0;
}