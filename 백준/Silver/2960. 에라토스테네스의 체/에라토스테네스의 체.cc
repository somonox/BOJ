#include<iostream>

using namespace std;

int mang[102444];
int a, b, jium;
int i, j;

int main() {
    cin >> a >> b;

    for (i = 2; i <= a; i++) {
        if (mang[i] == 0) {
            j = 0;
            while(1) {
                j++;
                if (i * j > a) break;
                if (mang[i * j] == 1) continue;
                mang[i * j] = 1;
                jium++;
                if (jium == b) {
                    cout << i * j << endl;
                    break;
                }
            }
        }
    }


    return 0;
}