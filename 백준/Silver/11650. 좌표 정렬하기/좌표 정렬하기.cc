#include<bits/stdc++.h>

using namespace std;

struct coord {
    int x;
    int y;
    bool operator<(const coord &other) const {
        return x < other.x || (x == other.x && y < other.y);
    }
};

vector<coord> v;
int num;
int i;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> num;
    v.resize(num);

    for (i = 0; i < num; i++) {
        int a, b;
        cin >> a >> b;
        v[i] = {a, b};
    }
    sort(v.begin(), v.end());

    for (i = 0; i < v.size(); i++)
        cout << v[i].x << " " << v[i].y << '\n';

    return 0;
}