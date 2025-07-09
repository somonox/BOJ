#include<iostream>
#include<algorithm>

using namespace std;

int num, color[1024444][3], m;
int i, j;

int main() {
    cin >> num;

    for(i = 0; i < num; i++)
        for (j = 0; j < 3; j++) 
            cin >> color[i][j];

    for (i = 1; i < num; i++) {
        color[i][0] += min(color[i - 1][1], color[i - 1][2]);
        color[i][1] += min(color[i - 1][0], color[i - 1][2]);
        color[i][2] += min(color[i - 1][0], color[i - 1][1]);
    }

    cout << *min_element(color[num-1], color[num-1] + 3) << endl;

    return 0;
}

