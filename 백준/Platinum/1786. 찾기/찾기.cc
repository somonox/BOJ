#include<iostream>
#include<vector>
#include<string>

using namespace std;

string a, b;

void lps(vector<int> &v) {
    int j = 0;
    v.resize(b.length());
    v[0] = 0;

    for (int i = 1; i < b.size(); i++) {
        while (j > 0 && b[i] != b[j])
            j = v[j - 1];

        if (b[i] == b[j])
            v[i] = ++j;
        else
            v[i] = 0;
    }
}

vector<int> kmp() {
    vector<int> v;
    vector<int> res;

    lps(v);

    int i = 0;
    int j = 0;

    while (i < a.size()) {
        if (a[i] == b[j]) {
            i++;
            j++;
        }

        if (j == b.size()) {
            res.push_back(i - j);
            j = v[j - 1];
        } else if (i < a.size() && a[i] != b[j]) {
            if (j != 0)
                j = v[j - 1];
            else
                i++;
        }
    }

    return res;
}

int main() {
    getline(cin, a);
    getline(cin, b);

    vector<int> v = kmp();

    cout << v.size() << endl;

    for (auto i : v) {
        cout << i + 1 << " ";
    }

    return 0;
}
