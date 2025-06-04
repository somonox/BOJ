#include<iostream>
#include<vector>
#define fastio ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0)

using namespace std;
using ll = long long;

vector<ll> prime;
ll cnt;
int num;
int i;

void linear_sieve() {
    // least prime factor
    vector<int> lp(num + 1, 0);
    for (int i = 2; i <= num; ++i) {
        if (lp[i] == 0) {
            lp[i] = i;
            prime.push_back(i);
        }
        for (int p : prime) {
            if (p > lp[i] || 1LL * i * p > num) break;
            lp[i * p] = p;
        }
    }
}

int main() {
    fastio;
    cin >> num;
    linear_sieve();
    vector<ll> ps(prime.size() + 1, 0);
    for (size_t i = 1; i <= prime.size(); ++i)
        ps[i] = ps[i - 1] + prime[i - 1];

    ll l = 0, r = 1;

    while (r < ps.size()) {
        if (ps[r] - ps[l] < num)
            r++;
        else if (ps[r] - ps[l] > num)
            l++;
        else {
            cnt++;
            l++;
        }

    }

    cout << cnt << endl;

    return 0;
}