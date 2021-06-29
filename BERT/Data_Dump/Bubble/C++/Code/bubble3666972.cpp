#include<iostream>
#include<cstdio>

using namespace std;

int main(){
    int n, cnt = 0;
    cin >> n;
    int A[n];
    for (int i = 0; i < n; i++) cin >> A[i];
    int flag = 1;
    while (flag) {
        flag = 0;
        for (int j = n-1; j > 0; j--){
            if (A[j] < A[j-1]){
                int a = A[j]; A[j] = A[j-1]; A[j-1] = a;
                flag = 1; cnt++;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        cout << A[i];
        if (i == n-1) cout << endl;
        else cout << " ";
    }
    cout << cnt << endl;
    return 0;
}
