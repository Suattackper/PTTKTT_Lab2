#include <bits/stdc++.h>
using namespace std;

int n, W, A[51], f[51][101];

int main() {
    cin >> n >> W;
    for (int i = 1; i <= n; i++) {
        cin >> A[i];
    }

    for (int i = 0; i <= n; i++) {
        f[i][0] = 0;
    }

    for (int w = 0; w <= W; w++) {
        f[0][w] = 0;
    }

    for (int i = 1; i <= n; i++) {
        for (int w = 1; w <= W; w++) {
            if (A[i] > w) {
                f[i][w] = f[i-1][w];
            } else {
                f[i][w] = max(f[i-1][w-A[i]] + A[i], f[i-1][w]);
            }
        }
    }

    cout << f[n][W] << endl;

    return 0;
}

