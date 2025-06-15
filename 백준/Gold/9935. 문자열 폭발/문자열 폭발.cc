#include <iostream>
#include <string>
#define fasti ios::sync_with_stdio(0); cin.tie(0);

using namespace std;

string s, explosion, result;
int len;

int main() {
    fasti;
    cin >> s >> explosion;
    
    len = explosion.length();

    for (char c : s) {
        result += c;
        if (result.size() >= len && result.substr(result.size() - len) == explosion)
            result.erase(result.end() - len, result.end());
    }

    cout << (result.empty() ? "FRULA" : result) << '\n';
}
