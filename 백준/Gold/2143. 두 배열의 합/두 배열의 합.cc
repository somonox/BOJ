#include<iostream>
#include <numeric>
#include<algorithm>

using namespace std;
using ll = long long;

vector<ll> ia, ib, a, b;
ll t, an, bn, lefty, righty, res;
ll i;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> t;

    cin >> an;

    ia.resize(an);

    for (auto &i : ia)
        cin >> i;

    cin >> bn;

    ib.resize(bn);

    for (auto &i : ib)
        cin >> i;

    for (ll i = 0; i < an; i++) {
        ll sum = 0;
        for (ll j = i; j < an; j++) {
            sum += ia[j];
            a.push_back(sum);
        }
    }
    for (ll i = 0; i < bn; i++) {
        ll sum = 0;
        for (ll j = i; j < bn; j++) {
            sum += ib[j];
            b.push_back(sum);
        }
    }

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());


    righty = b.size() - 1;


    while (lefty < a.size() && righty >= 0) {
        int sum = a[lefty] + b[righty];
        if (sum == t) {
            ll a_cnt = 1, b_cnt = 1;
            while (lefty + 1 < a.size() && a[lefty] == a[lefty + 1]) {
                a_cnt++;
                lefty++;
            }

            while (righty-1 >= 0 && b[righty] == b[righty - 1]) {
                b_cnt++;
                righty--;
            }
            res += a_cnt * b_cnt;
            lefty++;
            righty--;
        }
        else if (sum < t)
            lefty++;
        else
            righty--;
    }

    cout << res << endl;



    return 0;
}