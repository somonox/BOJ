#include <cstdint>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

static inline uint32_t toInt(uint32_t a, uint32_t b, uint32_t c, uint32_t d) {
    return (a << 24) | (b << 16) | (c << 8) | d;
}

static inline void printIP(uint32_t x) {
    cout << ((x >> 24) & 255) << '.' << ((x >> 16) & 255) << '.' << ((x >>  8) & 255) << '.' << (x & 255) << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    if (!(cin >> N)) return 0;

    vector<uint32_t> ip(N);
    for (int i = 0; i < N; ++i) {
        uint32_t a, b, c, d;
        char dot;
        cin >> a >> dot >> b >> dot >> c >> dot >> d;
        ip[i] = toInt(a, b, c, d);
    }

    uint32_t minIP = *min_element(ip.begin(), ip.end());
    uint32_t maxIP = *max_element(ip.begin(), ip.end());

    uint32_t diff = minIP ^ maxIP;
    int L = 32;
    while (diff) { diff >>= 1; --L; }

    uint32_t mask = (L == 0) ? 0 : (~0u << (32 - L));
    uint32_t network = minIP & mask;

    printIP(network);
    printIP(mask);
    return 0;
}
