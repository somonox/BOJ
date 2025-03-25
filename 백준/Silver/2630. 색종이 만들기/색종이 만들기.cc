#include<iostream>

using namespace std;

int sek[1024][1024];
int hayansek, paransek;
int num;
int i, j;

bool checkArea(int howmuch, int x, int y) {
    int areaColor = sek[x][y];
    for (int i = x; i < x + howmuch; i++)
        for (int j = y; j < y + howmuch; j++) 
            if (sek[i][j] != areaColor)
                return false;

    if (areaColor == 1)
        paransek++;
    else
        hayansek++;

    return true;
}


void ccsk(int sangsu, int x, int y) {
    if (checkArea(sangsu, x, y))
        return;

    ccsk(sangsu / 2, x, y);
    ccsk(sangsu / 2, x, y + sangsu / 2);
    ccsk(sangsu / 2, x + sangsu / 2, y);
    ccsk(sangsu / 2, x + sangsu / 2, y + sangsu / 2);
}

int main() {
    cin >> num;

    for (i = 0; i < num; i++)
        for (j = 0; j < num; j++)
            cin >> sek[i][j];

    ccsk(num, 0, 0);

    cout << hayansek << endl << paransek << endl;

    return 0;
}