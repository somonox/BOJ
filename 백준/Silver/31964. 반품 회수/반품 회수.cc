#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector<int> v, d;
int n, c;
int i;

int main() {
    cin >> n;

    for (i = 0; i < n; i++) {
        int tmp;
        cin >> tmp;
        v.push_back(tmp);
    }

    for (i = 0; i < n; i++) {
        int tmp;
        cin >> tmp;
        d.push_back(tmp);
    }

    int maxx = *max_element(v.begin(), v.end());
    c = maxx;
    if (maxx < d[v.size() - 1])
        c += d[v.size() - 1] - c;
    for (i = v.size() - 2; i >= 0; i--) {
        c += v[i + 1] - v[i];
        if (c < d[i])
            c += d[i] - c;
    }

    cout << c + v[0] << endl;

    return 0;
}