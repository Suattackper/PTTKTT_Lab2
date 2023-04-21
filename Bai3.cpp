#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Job {
    int time, value;
};

struct Machine {
    int time, cost;
};

int main() { 
    int n, m;
    cout<<"nhap n : "<<endl;
    cin >> n;
    cout<<"nhap m : "<<endl;
    cin >> m;
    vector<Job> jobs(n);
    vector<Machine> machines(m);
    vector<vector<int> > dp(n + 1, vector<int>(m + 1, 0));

    for (int i = 0; i < n; i++) {
        cin >> jobs[i].time >> jobs[i].value;
    }

    for (int i = 0; i < m; i++) {
        cin >> machines[i].time >> machines[i].cost;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            dp[i][j] = dp[i - 1][j];
            if (j >= jobs[i - 1].time && machines[j - 1].time >= jobs[i - 1].time) {
                dp[i][j] = max(dp[i][j], dp[i - 1][j - jobs[i - 1].time] + jobs[i - 1].value - machines[j - 1].cost);
            }
        }
    }

    cout << dp[n][m] << endl;
    return 0;
}
