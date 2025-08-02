#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector<string> v;
int n;
int i;

bool cmp(string a,string b) {
    if (a.size()==b.size())
        return a<b;
    return a.size()<b.size();
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    v.resize(n);

    for (string &i : v)
        cin >> i;

    sort(v.begin(), v.end(), cmp);
    v.erase(unique(v.begin(), v.end()), v.end());

    for (string i : v)
        cout << i << endl;

    return 0;
}