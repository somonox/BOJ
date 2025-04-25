#include<iostream>
#include<vector>
#include<set>

using namespace std;

vector<int> tp;
vector<vector<int>> p;
set<int> tr;
int parent[1024];
int n, m, truecnt;
int i, j;

int find(int x) {
    if (parent[x] == x) return x;
    return parent[x] = find(parent[x]);
}

void union_set(int a, int b) {
    int ap = find(a);
    int bp = find(b);

    if (ap != bp)
        parent[ap] = bp;
}

int main() {
    cin >> n >> m;

    cin >> truecnt;

    for (i = 1; i <= n; i++)
        parent[i] = i;

    for (i = 0; i < truecnt; i++) {
        int tmp;
        cin >> tmp;
        tp.push_back(tmp);
    }

    for (i = 0; i < m; i++) {
        int cnt;
        cin >> cnt;
        vector<int> tmpparty;
        for (j = 0; j < cnt; j++) {
            int tmp;
            cin >> tmp;
            tmpparty.push_back(tmp);
        }

        for (j = 0; j < tmpparty.size(); j++)
            union_set(tmpparty[0], tmpparty[j]);

        p.push_back(tmpparty);
    }

    for (auto i : tp)
        tr.insert(find(i));

    int a = 0;

    for (auto inpt : p) {
        bool flag = true;
        for (auto i : inpt) {
            if (tr.count(find(i)) > 0) {
                flag = false;
                break;
            }
        }
        if (flag)
            a++;
    }

    cout << a << endl;

    return 0;
}