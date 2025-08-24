#include<iostream>

using namespace std;

long long n, k = 1;
long long cnt[10];


int main() {
    cin >> n;

    while (k <= n) {
        long long lower = n % k;
        long long cur = (n / k) % 10;
        long long upper = n / (k * 10);

        for (int d = 0; d <= 9; d++) {
            cnt[d] += upper * k;

            if (cur > d)
                cnt[d] += k;
            else if (cur == d)
                cnt[d] += lower + 1;
        }

        cnt[0] -= k;

        k *= 10;
    }
    for (int i = 0; i < 10; i++)
        cout << cnt[i] << " ";

    return 0;
}