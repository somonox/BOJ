#include<iostream>

using namespace std;

int x, y, w, h;

int main() {
    cin >> x >> y >> w >> h;

    // 사각형 경계선 도달 x = 0, y = 0, x = w, y = h
    int sc1, sc2, sc3, sc4;
    sc1 = x;
    sc2 = y;
    sc3 = w - x;
    sc4 = h - y;
    cout << min(sc1, min(sc2, min(sc3, sc4))) << endl;;


    return 0;
}