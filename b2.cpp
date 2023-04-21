#include <bits/stdc++.h>
using namespace std;

struct Meeting {
    int start, end;
};

bool cmp(Meeting a, Meeting b) {
    return a.end < b.end;
}

int maxMeetings(Meeting arr[], int n) {
    sort(arr, arr+n, cmp);
    int count = 1;
    int curr_end = arr[0].end;
    for (int i = 1; i < n; i++) {
        if (arr[i].start > curr_end) {
            count++;
            curr_end = arr[i].end;
        }
    }
    return count;
}

int main() {
    Meeting arr[] = {{1, 3}, {2, 4}, {3, 5}, {4, 6}};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout << maxMeetings(arr, n) << endl;
    return 0;
} 
