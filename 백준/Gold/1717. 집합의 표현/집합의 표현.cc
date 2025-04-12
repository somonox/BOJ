#include<iostream>
#include<vector>

using namespace std;

vector<int> prnt;
int n, m;
int i;

int g(int x) {
    if (prnt[x] == x) return x;
    return prnt[x] = g(prnt[x]);
}

void f(int p, int q) {
    p = g(p);
    q = g(q);

    if (p < q)
        prnt[q] = p;
    else
        prnt[p] = q;
}

int main() {
    cin >> n >> m;

    prnt.resize(n + 2);
    for (i = 0; i <= n; i++)
        prnt[i] = i;

    for (i = 0; i < m; i++) {
        int op, a, b;
        scanf("%d%d%d", &op, &a, &b);

        if (op) {
            if (g(a) == g(b))
                printf("YES\n");
            else
                printf("NO\n");
        } else {
            f(a, b);
        }
    }

    return 0;
}