#include<iostream>
#include<vector>

using namespace std;

int n;
int grundy;

long long sfjsdfj(long long n){
    if(n==0 || n==2) return 0;
    if(n&1) return (n+1)/2;
    return (n-2)/2;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for (int i = 0; i < n; i++) {
        int tmp;
        cin >> tmp;
        grundy ^= sfjsdfj(tmp);
    }

    if (grundy)
        cout << "koosaga" << endl;
    else
        cout << "cubelover" << endl;
    return 0;
}