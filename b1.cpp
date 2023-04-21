#include <iostream>
using namespace std;

void timDayConTangDaiNhat(int a[], int n) {
    int L[n], prev[n], maxLen = 1, endIdx = 0;
        for (int i = 0; i < n; i++) {
            L[i] = 1;
            prev[i] = i;
            for (int j = 0; j < i; j++) {
                if (a[j] < a[i]) {
                    if (L[j] + 1 > L[i]) {
                        L[i] = L[j] + 1;
                        prev[i] = j;
                    }
                }
            }
            if (L[i] > maxLen) {
                maxLen = L[i];
                endIdx = i;
            }
        }
        int lis[maxLen], idx = maxLen - 1;
        lis[idx] = a[endIdx];
        while (idx > 0) {
            endIdx = prev[endIdx];
            lis[--idx] = a[endIdx];
        }
        for (int i = 0; i < maxLen; i++) {
            cout << lis[i] << " ";
        }
}

int main() {
   int n;
   cout<<"Nhap so luong phan tu cua mang: ";
   cin>>n;
   int a[n];
   for (int i=0; i<n;i++){
   	cout<<"Nhap phan tu thu a["<<i<<"] : ";
    cin>>a[i];
   }
   cout<<"day con tang co nhieu phan tu nhat cua day la: "<<endl;
   timDayConTangDaiNhat(a,n);
    return 0;
}

