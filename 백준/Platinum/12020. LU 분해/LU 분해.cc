#include <iostream>
using namespace std;

int n;
double upper[1001][1001], lower[1001][1001];

void print_state() {
    cout << "L = " << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << lower[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;

    cout << "U = " << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << upper[i][j] << " ";
        }
        cout << endl;
    }

    cout << endl;
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for(int i = 0; i < n; i++) {
        lower[i][i] = 1;
        for(int j = 0; j < n; j++)
            cin >> upper[i][j];
    }

    if(n==1) {
        cout << -1;
        return 0;
    }

    for(int i = 0; i < n; i++) {
        double pivot = upper[i][i];
        if(pivot == 0) {
            cout << -1;
            return 0;
        }

        double tmp = -(upper[i+1][i]/upper[i][i]);
        for(int j = 0; j < n; j++) {
            double val = upper[i][j] * tmp;
            upper[i+1][j] += val;
        }
        lower[i+1][i] = -tmp;
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++)
            printf("%.3lf ", lower[i][j]);
        printf("\n");
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++)
            printf("%.3lf ", upper[i][j]);
        printf("\n");
    }

}