#include<iostream>
#include<random>

using namespace std;

int a = 1, n = 1;

long long mod_pow(long long base, long long exp, long long mod) {
    long long result = 1;
    base %= mod;

    while (exp > 0) {
        if (exp % 2 == 1)
            result = (result * base) % mod;

        base = (base * base) % mod;
        exp /= 2;
    }

    return result;
}

bool miller_rabin(long long n, int k = 5) {
    if (n < 2) return false;
    if (n == 2 || n == 3) return true;
    if (n % 2 == 0) return false;

    long long d = n - 1;
    int s = 0;

    while (d % 2 == 0) {
        d /= 2;
        s++;
    }

    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<long long> dis(2, n - 2);

    for (int i = 0; i < k; i++) {
        long long a = dis(gen);
        long long x = mod_pow(a, d, n);

        if (x == 1 || x == n - 1)
            continue;

        bool found = false;
        for (int r = 1; r < s; r++) {
            x = mod_pow(x, 2, n);
            if (x == n - 1) {
                found = true;
                break;
            }
        }

        if (!found)
            return false;
    }

    return true;
}


int main() {
    while (true) {
        cin >> n >> a;
        if (a == n && a == 0)
            break;
        printf(!miller_rabin(n) && mod_pow(a, n, n) == a % n ? "yes\n" : "no\n");
    }

    return 0;
}