#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> findLongestWavio(vector<int>& arr) {
    int n = arr.size();

    vector<int> lis(n, 1), lds(n, 1);
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (arr[j] < arr[i]) {
                lis[i] = max(lis[i], lis[j] + 1);
            }
        }
    }
    for (int i = n - 2; i >= 0; i--) {
        for (int j = n - 1; j > i; j--) {
            if (arr[j] < arr[i]) {
                lds[i] = max(lds[i], lds[j] + 1);
            }
        }
    }

    int maxLength = 0;
    for (int i = 0; i < n; i++) {
        maxLength = max(maxLength, min(lis[i], lds[i]) * 2 - 1);
    }

    vector<int> result(maxLength);
    int index = maxLength - 1;
    for (int i = n - 1; i >= 0; i--) {
        if (lis[i] + lds[i] - 1 == maxLength) {
            result[index] = arr[i];
            index--;
        }
    }

    return result;
}

int main() {
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    vector<int> longestWavio = findLongestWavio(arr);

    for (int i = 0; i < longestWavio.size(); i++) {
        cout << longestWavio[i] << " ";
    }

    return 0;
}
