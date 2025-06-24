#include<iostream>
#include<numeric>
#include<vector>
#define fastio ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0)

using namespace std;

vector<int> parent;
bool available = true;
int g, p, cnt;
int i;

int find(int x) {
    if (parent[x] == x)
        return x;
    return parent[x] = find(parent[x]);
}

void dock(int x) {
    parent[x] = find(x - 1);
}

int main() {
    fastio;
    cin >> g >> p;
    parent.resize(g + 1);
    iota(parent.begin(), parent.end(), 0);

    for (i = 0; i < p; i++) {
        int tmp;
        cin >> tmp;

        if (available) {
            int finded = find(tmp);
            if (finded == 0) {
                available = false;
                cnt--;
            }
            cnt++;

            dock(finded);
        }
    }

    cout << cnt;

    return 0;
}