#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector<int> v;
int tmp;
int i;

int main() {
    for (i = 0; i < 9; i++) {
        cin >> tmp;
        v.push_back(tmp);
    }
    
    auto it = max_element(v.begin(), v.end());
    
    cout << *it << endl;
    cout << it - v.begin() + 1 << endl;
    
    return 0;
}