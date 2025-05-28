#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector<int> v;
int num;
int i;

int main() {
    cin >> num;
    for (i = 0; i < num; i++) {
        int tmp;
        cin >> tmp;
        v.push_back(tmp);
    }
    
    cout << *min_element(v.begin(), v.end()) << " " << *max_element(v.begin(), v.end()) << endl;
    
    return 0;
}