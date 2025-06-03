#include<iostream>
#include<vector>
#include<climits>
#include<cmath>
#include<algorithm>
#define fastio ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)

using namespace std;
using ll = long long;

vector<ll> v;
ll num, s1, s2, absmax = INT_MAX;
int i, j;

int main() {
    fastio;
    cin >> num;

    for (i = 0; i < num; i++) {
        ll tmp;
        cin >> tmp;
        v.push_back(tmp);
    }

    sort(v.begin(), v.end());

    int l = 0, r = num - 1;

    while (l < r) {
        if (abs(v[l] + v[r]) < absmax) {
            absmax = abs(v[l] + v[r]);
            s1 = v[l];
            s2 = v[r];
        }

        if (v[l] + v[r] > 0)
            r--;
        else
            l++;
    }

    cout << s1 << " " << s2 << endl;



    return 0;
}