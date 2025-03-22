#include<iostream>

using namespace std;

double a[1024], m;
double num, sum;
int i;

int main() {
    cin >> num;

    for (i = 0; i < num; i++) {
        cin >> a[i];
        m = max(m, a[i]);
    }

    for (i = 0; i < num; i++) {
        sum += (a[i]/m) * 100;
    }
    printf("%.20lf", sum / num);
    
    return 0;
}