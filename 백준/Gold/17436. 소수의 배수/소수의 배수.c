#include<stdio.h>

#define ll long long

ll v[10];
ll unions[10000];
ll complement[10000];
ll num, pc, unionsum, complementsum, cc;
ll i, j;

int main() {
    scanf("%lld %lld",&pc, &num);

    for (i = 0; i < pc; i++) {
        scanf("%lld", &v[i]);
        unions[i] = num / v[i];
    }

    for (ll mask = 1; mask < (1 << pc); ++mask) {
        if (__builtin_popcount((unsigned)mask) < 2)
            continue;
        ll comb[1000];
        int cnt = 0;
        for (ll i = 0; i < pc; ++i)
            if (mask >> i & 1) {
                comb[cnt++] = v[i];
            }
        ll sum = 1;
        for (ll i = 0; i < cnt; ++i) {
            sum *= comb[i];
        }
        if (cnt % 2 == 0)
            sum = -sum;
        complement[cc++] = num / sum;
    }

    for (i = 0; i < pc; i++) {
        unionsum += unions[i];
    }

    for (i = 0; i < cc; i++) {
        complementsum += complement[i];
    }

    printf("%lld\n", unionsum + complementsum);


    return 0;
}