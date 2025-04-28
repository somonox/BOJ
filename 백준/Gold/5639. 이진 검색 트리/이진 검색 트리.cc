#include <iostream>
#include <vector>

using namespace std;

vector<int> preorder;

void dfs(int start, int end) {
    if (start >= end) return;

    int root = preorder[start];
    int right = start + 1;

    while (right < end && preorder[right] < root)
        right++;

    dfs(start + 1, right);
    dfs(right, end);

    cout << root << '\n';
}

int main() {
    int x;
    while (cin >> x)
        preorder.push_back(x);

    dfs(0, preorder.size());
}
