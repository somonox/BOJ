#include<bits/stdc++.h>

using namespace std;

vector<char> chars;
string 콤비네이숑;
int r, n;
int i;

bool contains_vowel(string s) {
    int cnt = 0;
    for (char c : s)
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
            cnt++;

    return (cnt > 0 && s.size() - cnt > 1);
}

void combination(int idx, int depth) {
    if (depth == r)
        if (contains_vowel(콤비네이숑))
            cout << 콤비네이숑 << '\n';

    for (int i = idx; i < n; i++) {
        콤비네이숑 += chars[i];
        combination(i + 1, depth + 1);
        콤비네이숑.pop_back();
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> r >> n;

    chars.resize(n);
    for (auto &c : chars)
        cin >> c;

    sort(chars.begin(), chars.end());

    combination(0, 0);

    return 0;
}