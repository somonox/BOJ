#include <iostream>
#include<algorithm>

using namespace std;

string final;
string start;

int main() {
    cin >> final >> start;

    while (true) {
        if (start == final) {
            break;
        }
        if (start.back() == 'B') {
            start.pop_back();
            reverse(start.begin(), start.end());
        } else if (start.back() == 'A') {
            start.pop_back();
        } else {
            cout << 0 << endl;
            return 0;
        }
    }

    cout << 1 << endl;

    return 0;
}