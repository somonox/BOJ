#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    long long l;
    cin >> n >> l;

    vector<pair<long long, long long>> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i].first >> v[i].second;
    }

    sort(v.begin(), v.end());

    long long pos = 0;
    long long cnt = 0;

    for (int i = 0; i < n; i++) {
        long long start = max(pos, v[i].first);
        long long end = v[i].second;

        if (start >= end) continue;

        long long length = end - start;
        long long need = (length + l - 1) / l;
        cnt += need;
        pos = start + need * l;
    }

    cout << cnt << "\n";
    return 0;
}
