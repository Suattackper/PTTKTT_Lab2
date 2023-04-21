#include <bits/stdc++.h>
using namespace std;

struct order {
    int start, end, cost;
};

bool cmp(order a, order b) {
    return a.end < b.end;
}

int main() {
    int n;
    cin >> n;

    vector<order> orders(n);
    for (int i = 0; i < n; i++) {
        cin >> orders[i].start >> orders[i].end >> orders[i].cost;
    }

    sort(orders.begin(), orders.end(), cmp);

    vector<int> opt(n);
    opt[0] = orders[0].cost;

    for (int i = 1; i < n; i++) {
        opt[i] = orders[i].cost;
        for (int j = i - 1; j >= 0; j--) {
            if (orders[j].end <= orders[i].start) {
                opt[i] = max(opt[i], orders[i].cost + opt[j]);
                break;
            }
        }
        opt[i] = max(opt[i], opt[i-1]);
    }

    cout << opt[n-1] << endl;
    return 0;
}

