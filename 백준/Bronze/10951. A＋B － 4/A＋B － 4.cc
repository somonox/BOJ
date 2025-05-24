#include<iostream>

using namespace std;

int a, b;

int main() {
    ios::sync_with_stdio(NULL);
    cin.tie(NULL);
    cout.tie(NULL);
    
    while(cin >> a >> b) {
        cout << a + b << endl;
    }
    
    return 0;
}