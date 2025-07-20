#include<iostream>

using namespace std;

int t;
int i, j;
string s;

int main() {
    cin >> t;
    for (i = 0; i < t; i++) {
        int num;
        cin >> num;
        cin >> s;
        for (auto c:s) {
            for (j = 0; j < num; j++)
                cout << c;
        }
        cout << '\n';
    }

    return 0;
}