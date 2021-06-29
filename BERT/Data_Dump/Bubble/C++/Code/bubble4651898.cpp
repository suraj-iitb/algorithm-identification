#include<iostream>
using namespace std;
int main() {
    int n, flag, cnt=0;
    cin >> n;
    int A[n];
    for (int i=0; i<n; i++){
        cin >> A[i];
    }
    flag = 1;
    while (flag){
        flag = 0;
        for (int j=n-1; j>0; j--){
            if (A[j] < A[j-1]){
                swap(A[j], A[j-1]);
                flag = 1;
                cnt += 1;
            }
        }
    }
    for (int i=0; i<n; i++){
        if (i==n-1){
            cout << A[i] << endl;
        } else {
            cout << A[i] << " ";
        }
    }
    cout << cnt << endl;
    return 0;
}
