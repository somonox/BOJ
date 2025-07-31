#include<iostream>
#include<vector>

using namespace std;

vector<vector<int>> v;
// 0 == uncolored, 1 == red, 2 == blue
vector<char> color;
int t, ve, e;
int i, j;

bool dfs(int a) {
    for (int vv : v[a]) {
        if (color[vv] == 0) {
            color[vv] = 3 - color[a];
            if (!dfs(vv)) return false;
        } else if (color[vv] == color[a]) {
            return false;
        }
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> t;

    for (i = 0; i < t; i++) {
        cin >> ve >> e;
        v.resize(ve + 1);
        color.resize(ve + 1);
        int vw, vv;
        for (j = 0; j < e; j++) {
            cin >> vw >> vv;
            v[vw].push_back(vv);
            v[vv].push_back(vw);
        }
        bool good = true;
        for (int j = 1; j <= ve && good; ++j) {
            if (color[j] == 0) {
                color[j] = 1;
                if (!dfs(j)) good = false;
            }
        }
        cout << (good ? "YES\n" : "NO\n");
        v.clear();
        color.clear();
    }



    return 0;
}
