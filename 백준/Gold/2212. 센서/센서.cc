#include<iostream>
#include<vector>
#include<algorithm>
#include<set>

using namespace std;

vector<int> s;
vector<int> fs;
int n, k;
int i;

int main() {
    cin >> n >> k;

    int inp;
    for (i = 0; i < n; i++) {
        cin >> inp;
        s.push_back(inp);
    }
    sort(s.begin(), s.end());
    s.erase(unique(s.begin(), s.end()), s.end());
    for (i = 0; i < s.size() - 1; i++)
        fs.push_back(s.at(i + 1) - s.at(i));
    sort(fs.begin(), fs.end(), greater<int>());

    int sum = 0;
    for (i = k - 1; i < fs.size(); i++) {
        sum += fs.at(i);
    }

    cout << sum << endl;


    return 0;
}