#include<bits/stdc++.h>

using namespace std;

vector<int> v;
vector<int> res;

int num;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    while (cin >> num) {
        v.resize(num);
        for (auto &i : v)
            cin >> i;
        for (auto i : v) {
            auto it = lower_bound(res.begin(), res.end(), i);
            if (it == res.end())
                res.push_back(i);
            else
                *it = i;
        }
        cout << res.size() << '\n';
        res.clear();
        v.clear();
    }

    return 0;
}