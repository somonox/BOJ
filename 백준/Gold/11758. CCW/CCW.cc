#include<iostream>

using namespace std;

int x1, x2, x3, yy1, y2, y3;

int main() {
    cin >> x1 >> yy1 >> x2 >> y2 >> x3 >> y3;
    double cross = (x2 - x1) * (y3-yy1) - (y2-yy1) * (x3-x1);

    if (cross > 0)
        cout << 1 << endl;
    else if (cross < 0)
        cout << -1 << endl;
    else
        cout << 0 << endl;


    return 0;
}