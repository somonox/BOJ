#include<iostream>
#include<cmath>

using namespace std;

int num, cnt;
int i;

int main() {
    cin >> num;

    for (i = 2; i <= num; i++) {
        while (num % i == 0) {
            num /= i;
            cnt++;
        }
        if (num == 1)
            break;
    }

    cout << ceil(log2(cnt)) << endl;
}