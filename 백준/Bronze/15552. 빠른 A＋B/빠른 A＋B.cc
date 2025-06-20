#include<iostream>
#define fastio ios::sync_with_stdio(NULL), cin.tie(NULL), cout.tie(NULL)

using namespace std;

int num;

int main() {
    fastio;
    cin >> num;
    
    for (int i = 0; i < num; i++) {
        int a, b;
        cin >> a >> b;
        cout << a + b << "\n";
    }
    
    
    return 0;
}