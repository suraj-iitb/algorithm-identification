#include<iostream>
using namespace std;
int main() {
    int n, minj, cnt = 0;
    cin >> n;
    int A[n];
    for (int i=0; i<n; i++){
        cin >> A[i];
    }
    for (int i=0; i<n; i++){
        minj = i;
        for (int j=i; j<n; j++){
            if (A[j] < A[minj]){
                minj = j;
            }
        }
        if (A[i] != A[minj]) cnt += 1;
        swap(A[i], A[minj]);
    }
    for (int i=0; i<n; i++){
        if (i == n-1){
            cout << A[i] << endl;
        } else {
            cout << A[i] << " ";
        }
    }
    cout << cnt << endl;
    return 0;
}

