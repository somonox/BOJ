#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#define fastio ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0)

using namespace std;

vector<pair<int,int>> v;
vector<int> kq;
int n, k, ans;
int i;

int main() {
    fastio;
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif

    cin >> n >> k;

    for (i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        v.push_back(make_pair(a, b));
    }

    for (i = 0; i < k; i++) {
        int a;
        cin >> a;
        kq.push_back(a);
    }
    sort(v.begin(), v.end());
    sort(kq.begin(), kq.end());

    priority_queue<int> pq;
    long long ans = 0;
    int j = 0;

    for (int i = 0; i < k; i++) {
        while (j < n && v[j].first <= kq[i]) {
            pq.push(v[j].second);
            j++;
        }

        if (!pq.empty()) {
            ans += pq.top();
            pq.pop();
        }
    }

    cout << ans << '\n';


    return 0;
}