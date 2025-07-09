#include<iostream>

using namespace std;

int n, k, kpk = 1, npr = 1;
int i;

int main() {
    cin >> n >> k;
    
    for (i = 1; i <= k; i++)
        kpk *= i;
    
    for (i = (n - k) + 1; i <= n; i++)
        npr *= i;
    
    cout << npr / kpk << endl;
    
    return 0;
}