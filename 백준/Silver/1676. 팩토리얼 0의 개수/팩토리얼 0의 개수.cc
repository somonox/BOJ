#include<iostream>

using namespace std;

int num, ct, cf;
int i;

int main() {
    cin >> num;

    for (i = 1; i <= num; i++) {
        int tmp = i;
        while (tmp % 2 == 0) {
            ct++;
            tmp = tmp / 2;
        }
        while (tmp % 5 == 0) {
            cf++;
            tmp = tmp / 5;
        }
    }

    cout << min(ct, cf) << endl;

    return 0;
}