#include<iostream>
#include<cstdio>

using namespace std;

int main(){
    int n, cnt = 0, minj;
    cin >> n;
    int A[n];
    for (int i = 0; i < n; i++) cin >> A[i];
    for (int i = 0; i < n; i++) {
        minj = i;
        for (int j = i; j < n; j++){
            if (A[j] < A[minj]) minj = j;
        }
        int a = A[i]; A[i] = A[minj]; A[minj] = a;
        if (i != minj) cnt++;
    }
    for (int i = 0; i < n; i++) {
        cout << A[i];
        if (i == n-1) cout << endl;
        else cout << " ";
    }
    cout << cnt << endl;
    return 0;
}
