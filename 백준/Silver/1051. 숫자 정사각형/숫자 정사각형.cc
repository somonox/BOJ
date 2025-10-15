#include<bits/stdc++.h>

#define FASTIO ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define DLOOP(w, n) for (w = 0; w < n; w++)
#define RLOOP(w, n, k) for (w = n; w <= k; w++)
#define LOOP while (true)
#define LOOPN(n) while(n--)
#define FILLV(v, k) v.resize(k); for (auto &i : v)
#define OUTRBL(v) for (auto &i : v)
#define FINP freopen("input.txt", "r", stdin)
#define INPS(n) cin >> n
#define OUTLNWV(v) cout << v << endl
#define OUTLN cout << endl
#define OUTV(v) cout << v << " "
#define IFBRK(exprs) if (exprs) break

#define TL __int128_t
#define ULL unsigned long long
#define LL long long
using namespace std;

int matrix[51][51];
int a, b, res;
int i, j, k;

bool valid(int x, int y, int perimeter) {
    int cmprtr = matrix[x][y];
    int rightX = x + perimeter - 1;
    int downY = y + perimeter - 1;
    //cout << cmprtr << " " << matrix[rightX][y] << " " << matrix[x][downY] << " " << matrix[rightX][downY] << " " << perimeter << " " << x << " " << y << endl;
    return (cmprtr == matrix[rightX][y] && cmprtr == matrix[x][downY] && cmprtr == matrix[rightX][downY]) && (x + perimeter - 1 < a && y + perimeter - 1 < b);
}

int main() {
    INPS(a);
    INPS(b);

    DLOOP(i, a)
        DLOOP(j, b)
            scanf ("%1d", &matrix[i][j]);

    int maxy = max(a, b);

    DLOOP(i, a)
        DLOOP(j, b)
            RLOOP(k, 1, maxy)
                if (valid(i, j, k))
                    res = max(res, k);

    OUTLNWV(res * res);


    return 0;
}