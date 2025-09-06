#include<bits/stdc++.h>

using namespace std;

int n, cnt;

bool check(string str) {
    bool chec[27];
    memset(chec, 0, sizeof(chec));
    chec[str[0] - 'a'] = true;
    for (int i = 1; i < str.length(); i++) {
        if (str[i - 1] != str[i] && chec[str[i] - 'a'])
            return false;
        chec[str[i] - 'a'] = true;
    }
    return true;
}

int main() {
    cin >> n;
    while (n--) {
        string str;
        cin >> str;
        if (check(str))
            cnt++;
    }

    cout << cnt << endl;

    return 0;
}