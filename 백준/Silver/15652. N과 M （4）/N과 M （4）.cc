#include<iostream>
#include<vector>

using namespace std;

vector<int> v;
int chaedae, yul;
 
void backtrack(int start, int depth){
    if (depth == yul) {
        for (int i = 0; i < yul; i++)
            printf("%d ", v[i]);
        printf("\n");

        return;
    }

    for (int i = start; i <= chaedae; i++) {
        v.push_back(i);
        backtrack(i, depth + 1);
        v.pop_back();
    }
}

int main() {
    cin >> chaedae >> yul;

    backtrack(1, 0);

    return 0;
}