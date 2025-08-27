#include <bits/stdc++.h>
using namespace std;

vector<long long> a;
long long x;
long long n;

int main(){
    cin >> n;
    a.resize(n);
    for(auto &i : a) {
        cin >> i;
        x ^= i;
    }
    if(x == 0) {
        cout << 0;
        return 0;
    }
    long long ans = 0;
    for(long long h : a)
        if ((h ^ x) < h)
            ans++;
    cout << ans;
    return 0;
}
