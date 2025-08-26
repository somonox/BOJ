#include<iostream>
#include<vector>
#include<algorithm>
#include<iterator>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

using namespace std;

vector<int> arr, res, tail_idx, parent;
int num;
int i;

int main() {
    fastio;
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    cin >> num;
    parent.resize(num, -1);
    // One-line input trick
    vector<int> arr{istream_iterator<int>(cin), istream_iterator<int>()};
    for (i = 0; i < num; i++) {
        vector<int>::iterator it = lower_bound(res.begin(), res.end(), arr[i]);
        int pos = int(it - res.begin());
        if (it == res.end()) {
            res.push_back(arr[i]);
            tail_idx.push_back(i);
        } else {
            *it = arr[i];
            tail_idx[pos] = i;
        }
        if (pos > 0)
            parent[i] = tail_idx[pos - 1];
    }

    vector<int> lis;
    for (int cur = tail_idx.back(); cur != -1; cur = parent[cur]) lis.push_back(arr[cur]);
    reverse(lis.begin(), lis.end());

    cout << lis.size() << '\n';
    for (int i = 0; i < (int)lis.size(); i++) {
        if (i) cout << ' ';
        cout << lis[i];
    }

    return 0;
}