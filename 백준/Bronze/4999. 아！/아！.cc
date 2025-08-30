#include<iostream>

using namespace std;

string a, b;

int main() {
    cin >> a >> b;
    
    if (a.length() >= b.length())
        cout << "go" << endl;
    else
        cout << "no" << endl;
    
    return 0;
}