#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

vector<int> v;
int num;
int i;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> num;

    for (i = 0; i < num; i++) {
        int a;
        cin >> a;
        v.push_back(a);
    }

    sort(v.begin(), v.end());

    for (i = 0; i < v.size(); i++) {
        cout << v[i] << '\n';
    }

    return 0;
}