#include<iostream>
#include<algorithm>

using namespace std;

vector<pair<int, int>> v;
int num;
int i;

bool comp(pair<int, int> p1, pair<int, int> p2) {
    if (p1.second == p2.second)
        return p1.first < p2.first;
    return p1.second < p2.second;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> num;

    for (i = 0; i < num; i++) {
        int a, b;
        cin >> a >> b;
        v.push_back({a, b});
    }

    sort(v.begin(), v.end(), comp);

    for (i = 0; i < v.size(); i++) {
        cout << v[i].first << " " << v[i].second << '\n';
    }

    return 0;
}