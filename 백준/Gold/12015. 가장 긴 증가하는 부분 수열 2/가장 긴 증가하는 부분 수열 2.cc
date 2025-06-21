#include<iostream>
#include<vector>
#include<algorithm>
#include<iterator>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

using namespace std;

vector<int> arr, res;
int num;
int i;

int main() {
    fastio;
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    cin >> num;
    // One-line input trick
    vector<int> arr{istream_iterator<int>(cin), istream_iterator<int>()};
    for (i = 0; i < num; i++) {
        vector<int>::iterator it = lower_bound(res.begin(), res.end(), arr[i]);
        if (it == res.end())
            res.push_back(arr[i]);
        else
            *it = arr[i];
    }

    cout << res.size() << endl;

    return 0;
}