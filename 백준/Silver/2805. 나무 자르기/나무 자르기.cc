#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

unsigned long long num, gilee;
vector<unsigned long long> namu;
unsigned long long i, j;

bool dodal(unsigned long long m) {
    unsigned long long sum = 0;
    for (unsigned long long i : namu) {
        if (i > m)
            sum += i - m;
    }

    return sum >= gilee;
}

int main() {
    cin >> num >> gilee;

    for (i = 0; i < num; i++) {
        unsigned long long tmp;
        cin >> tmp;
        namu.push_back(tmp);
    }

    unsigned long long f, m, e;
    f = 0;
    e = *max_element(namu.begin(), namu.end());
    
    unsigned long long res;

    while (f <= e) {
        m = (f + e) / 2;
        if (dodal(m)) {
            res = m;
            f = m + 1;
        } else {
            e = m - 1;
        }
    }

    cout << res << endl;

    return 0;
}