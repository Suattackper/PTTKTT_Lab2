#include <iostream>
using namespace std;

const int MAXN = 50;
const int MAXW = 100;

int A[MAXN+5], C[MAXN+5], dp[MAXN+5][MAXW+5];

int main() {
    int n, W;
    cin >> n >> W;
    for (int i = 1; i <= n; i++) {
        cin >> A[i] >> C[i];
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= W; j++) {
            dp[i][j] = dp[i-1][j];
            if (j >= A[i]) {
                dp[i][j] = max(dp[i][j], dp[i-1][j-A[i]] + C[i]);
            }
        }
    }

    cout << dp[n][W] << endl;
    return 0;
}

