#include<iostream>

using namespace std;

int arr[6] = {1, 1, 2, 2, 2, 8};
int i;

int main() {
    for (i = 0; i < 6; i++) {
        int tmp;
        cin >> tmp;
        cout << arr[i] - tmp << " ";
    }
    
    return 0;
}