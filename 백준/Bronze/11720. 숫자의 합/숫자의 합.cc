#include<iostream>

using namespace std;

int num;
int sum;
int i;

int main() {
    cin >> num;

    for (i = 0; i < num; i++) {
        int tmp;
        scanf("%1d", &tmp);
        sum += tmp;
    }

    cout << sum << endl;

    return 0;
}