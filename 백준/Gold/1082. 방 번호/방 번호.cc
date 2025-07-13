#include<iostream>
#include<vector>

using namespace std;

vector<int> v;
int num, money;
string dp[1024];
int i, j;


string strmax(const string& a, const string& b) {
    string sa = a;
    string sb = b;
    sa.erase(0, sa.find_first_not_of('0'));
    sb.erase(0, sb.find_first_not_of('0'));


    if (sa.length() > sb.length()) return sa;
    if (sa.length() < sb.length()) return sb;
    return (sa > sb) ? sa : sb;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> num;
    v.resize(num);

    for (auto& i : v)
        cin >> i;

    cin >> money;

    dp[money] = "";
    for (i = money; i >= 0; i--) {
        for (j = 0; j < v.size(); j++) {
            if (i - v[j] < 0)
                continue;
            dp[i - v[j]] = strmax(dp[i - v[j]], dp[i] + to_string(j));
        }
        if (i > 1)
            dp[i - 1] = strmax(dp[i - 1], dp[i]);
    }

    if (dp[0] == "")
        cout << 0 << '\n';
    else
        cout << dp[0] << '\n';


    return 0;
}