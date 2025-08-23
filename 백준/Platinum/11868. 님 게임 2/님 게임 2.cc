#include<iostream>

using namespace std;

int n;
int grundy;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n;
    for (int i = 0; i < n; i++) {
        int tmp;
        cin >> tmp;
        grundy ^= tmp;
    }

    if (grundy)
        cout << "koosaga" << endl;
    else
        cout << "cubelover" << endl;
    return 0;
}