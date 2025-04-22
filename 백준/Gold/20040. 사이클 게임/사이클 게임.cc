#include<iostream>
#include<vector>

using namespace std;

vector<int> parent;
int n, m;
int i;

int find(int a) {
    if (a == parent[a])
        return a;
    else
        return parent[a] = find(parent[a]);
}

bool union_find(int a, int b) {
    a = find(a);
    b = find(b);

    if (a == b)
        return true;
    if(a != b) parent[a]=b;

    return false;
}

int main() {
    cin >> n >> m;

    parent.resize(n);
    for (i = 0; i < n; i++)
        parent[i] = i;

    for (i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        if(union_find(a, b)) {
            cout << i + 1 << endl;
            return 0;
        }
    }

    cout << 0 << endl;




    return 0;
}