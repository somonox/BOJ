#include <iostream>

using namespace std;

int digitsum(int num) {
    int sum = 0;
    while (num != 0) {
        sum += num % 10;
        num /= 10;
    }
    return sum;
}
int num, tmp, mon;

int main() {
    cin >> num;
    tmp = num;

    while (tmp != 0) {
        if (tmp + digitsum(tmp) == num)
             mon = tmp;
        tmp--;
    }

    cout << mon << '\n';
    return 0;
}