#include<iostream>
#include<vector>
#define M 1e6

using namespace std;
using ll = long long;

vector<ll> fib = {0, 1};
ll num;
ll i;

int main() {
    cin >> num;
    const ll P = 15 * 1e5;

    if (num == 1)
        cout << 1 << endl;
    else {
        for (i = 2; i <= num % P; i++) {
            fib.push_back((fib[i - 1] + fib[i - 2]) % (ll)M);
        }
        cout << fib[num % P] << endl;
    }


    return 0;
}