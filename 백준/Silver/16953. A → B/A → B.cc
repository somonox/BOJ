#include<iostream>
#include<vector>
#include<climits>

using namespace std;

vector<int> dp;
bool flag = true;
unsigned long long n, m, c;
unsigned long long i;

int main() {
    cin >> n >> m;
    


    for (i = m; i >= n; i--) {
        if (m == n) {
            flag = false;
            break;
        }

        if (m % 10 == 1)
            m /= 10;
        else if (m % 2 == 0)
            m /= 2;
        
        c++;
    }
    if (flag)
        cout << "-1" << endl;
    else
        cout << c + 1 << endl;

    return 0;
}