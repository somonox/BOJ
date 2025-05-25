#include<iostream>
#include<vector>

using namespace std;

vector<int> v;
int num;
int i;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> num;

    for (i =0; i < num; i++) {
        int tmp;
        cin >> tmp;
        v.push_back(tmp);
    }

    v.push_back(0);


    for (i = num; i >= 0; i--) {
        if (v[i - 1] - v[i] > 1) {
            v[i - 1] = (v[i] + 1) % v[i - 1];
        }
    }
    int sum = 0;
    for (i = 0; i < v.size(); i++) {
        sum += v[i];
    }

    cout << sum << endl;

    return 0;
}