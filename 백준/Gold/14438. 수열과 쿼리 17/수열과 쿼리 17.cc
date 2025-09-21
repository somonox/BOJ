#include<bits/stdc++.h>

using namespace std;

const long long MINF = INT_MAX;
long long n, m;

long long arr[100001];
long tree[400004];

void init(long long start, long long end, long long cur) {
    if(start == end) {
        tree[cur] = arr[start];
    }
    else {
        long long mid = (start+end)/2;
        init(start, mid, cur*2);
        init(mid+1, end, cur*2+1);
        tree[cur] = min(tree[cur*2], tree[cur*2+1]);
    }
}

long long find(long long start, long long end, long long left, long long right, long long cur) {
    if(start > right || end < left)
        return MINF;
    if(left <= start && end <= right)
        return tree[cur];
    long long mid = (start+end)/2;
    return min(find(start, mid, left, right, cur*2), find(mid+1, end, left, right, cur*2+1));
}

void update(long long start, long long end, long long idx, long long val, long long cur) {
    if(start > idx || end < idx) return;
    if(start == end) {
        tree[cur] = val;
        return;
    }
    long long mid = (start+end)/2;
    update(start, mid, idx, val, cur*2);
    update(mid+1, end, idx, val, cur*2+1);
    tree[cur] = min(tree[cur*2], tree[cur*2+1]);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    for(long long i = 0; i < n; i++)
        cin >> arr[i];

    init(0, n-1, 1);

    cin >> m;
    for(long long i = 0; i < m; i++) {
        long long a, b, c;
        cin >> a >> b >> c;

        if(a == 1) {
            update(0, n-1, b-1, c, 1);
        }
        else {
            cout << find(0, n-1, b-1, c-1, 1) << '\n';
        }
    }
}