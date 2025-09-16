#include<iostream>
#include<vector>

using namespace std;

typedef struct {
    int x1, y1, x2, y2;
} edge;

vector<edge> edges;
vector<int> parents;
int num;

int find(int x) {
    if (parents[x] < 0)
        return x;
    return parents[x] = find(parents[x]);
}

void unions(int a, int b) {
    a = find(a); b = find(b);
    if (a == b) return;
    if (parents[a] > parents[b]) swap(a, b);
    parents[a] += parents[b];
    parents[b] = a;
}


int ccw(pair<int, int> p1, pair<int, int> p2, pair<int, int> p3) {
    int ret = (p1.first * p2.second + p2.first * p3.second + p3.first * p1.second) - (p2.first * p1.second + p3.first * p2.second + p1.first * p3.second);
    if (ret < 0) return -1;
    if (ret > 0) return 1;
    return 0;
}

bool is_crossing(edge e1, edge e2) {
    pair<int, int> p1 = make_pair(e1.x1, e1.y1);
    pair<int, int> p2 = make_pair(e1.x2, e1.y2);
    pair<int, int> p3 = make_pair(e2.x1, e2.y1);
    pair<int, int> p4 = make_pair(e2.x2, e2.y2);

    int p1p2 = ccw(p1, p2, p3) * ccw(p1, p2, p4);
    int p3p4 = ccw(p3, p4, p1) * ccw(p3, p4, p2);

    if (p1p2 == 0 && p3p4 == 0) {
        if (p1 > p2)
            swap(p1, p2);
        if (p3 > p4)
            swap(p3, p4);

        return (p2 >= p3 && p4 >= p1);
    }

    return p1p2 <= 0 && p3p4 <= 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> num;
    parents.resize(num + 1, -1);

    for (int i = 0; i < num; i++) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        edges.push_back({x1, y1, x2, y2});
    }

    for (int i = 0; i < num; i++)
        for (int j =  i + 1; j < num; j++)
            if (is_crossing(edges[i], edges[j]))
                unions(i, j);

    int group_count = 0;
    int max_size = 0;
    for (int i = 0; i < num; i++)
        if (parents[i] < 0) {
            group_count++;
            max_size = max(max_size, -parents[i]);
        }

    cout << group_count << "\n" << max_size << "\n";

    return 0;
}