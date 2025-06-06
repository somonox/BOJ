#include <iostream>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

using namespace std;

string str;
int num;
int i;

int main() {
    fastio;
    cin >> num;

    for (i = 0; i < num; i++) {
        cin >> str;
        int sum = 0;
        int score = 1;
        for (char c : str) {
            if (c == 'O')
                sum += score++;
            else
                score = 1;
        }
        cout << sum << endl;
    }

    return 0;
}