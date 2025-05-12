#include <iostream>
#include<vector>

using namespace std;

const int MAX_N = 500'000;
int A[MAX_N + 1];
int tmp[MAX_N + 1];
long long cnt = 0;
int K;

void merge(int p, int q, int r) {
    int i = p, j = q + 1, t = 1;

    while (i <= q && j <= r) {
        if (A[i] <= A[j]) tmp[t++] = A[i++];
        else              tmp[t++] = A[j++];
    }
    while (i <= q) tmp[t++] = A[i++];
    while (j <= r) tmp[t++] = A[j++];

    i = p;  t = 1;
    while (i <= r) {
        A[i] = tmp[t];
        if (++cnt == K) cout << A[i] << '\n';
        ++i; ++t;
    }
}

void merge_sort(int p, int r) {
    if (p < r) {
        int q = (p + r) >> 1;
        merge_sort(p, q);
        merge_sort(q + 1, r);
        merge(p, q, r);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N >> K;
    for (int i = 1; i <= N; ++i) cin >> A[i];

    merge_sort(1, N);

    if (cnt < K) cout << -1 << '\n';
    return 0;
}
