#include<iostream>
#include<vector>

using namespace std;

vector<int> v;
int num, cnt;
int i;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> num;
    v.resize(num);

    for (auto &i : v)
        cin >> i;

    for (i = 1; i < num; i++) {
        while (v[i] < v[i - 1]) {
            v[i] *= 2;
            cnt++;
        }
    }

    cout << cnt << endl;



    return 0;
}