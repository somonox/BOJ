#include<iostream>
#include<sstream>

using namespace std;

string str, tmp;
int cnt;

int main() {
    getline(cin, str, '\n');
    istringstream iss(str);

    while (iss >> tmp)
        cnt++;

    cout << cnt << endl;

    return 0;
}