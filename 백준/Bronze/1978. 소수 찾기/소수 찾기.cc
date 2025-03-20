#include<iostream>

using namespace std;

int num;

bool isPrime(int a) {
    int i = 2;

    if (a == 1)
        return false;

    while(i * i <= a) {
        if (a % i == 0)
            return false; 
        i++;
    }
    return true;
}

int main() {
    cin >> num;

    int sum = 0;
    for (int i = 0; i < num; i++) {
        int tmp;
        cin >> tmp;
        if(isPrime(tmp)) {
            sum++;
        }
    }

    cout << sum << endl;

    return 0;
}