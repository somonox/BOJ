#include<iostream>
#include<map>
#include<algorithm>
#include<vector>

using namespace std;

map<int, int> m;
vector<int> tmpv;
vector<int> hehe;
int c;
int num;
int i;

int main() {
    cin >> num;

    for (i = 0; i < num; i++) {
        int tmp;
        scanf("%d", &tmp);
        tmpv.push_back(tmp);
    }

    hehe = tmpv;

    sort(tmpv.begin(), tmpv.end());

    for (i = 0; i < num; i++) {
        if (m.count(tmpv[i]) > 0)
            continue;
        m[tmpv[i]] = c;
        c++;
    }

    for (i = 0; i < num; i++){
        printf("%d ", m[hehe[i]]);
    }
    cout << endl;

    return 0;
}