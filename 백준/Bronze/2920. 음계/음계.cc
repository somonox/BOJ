#include<iostream>

using namespace std;

bool asc = true, desc = true;
int tmp;
int i;

int main() {
    for (int i = 1; i <= 8; ++i) {
        cin >> tmp;
        if (tmp != i)
            asc = false;
        if (tmp != 9 - i)
            desc = false;
    }

    if (asc)
        cout << "ascending" << endl;
    else if (desc)
        cout << "descending" << endl;
    else
        cout << "mixed" << endl;

    return 0;
}