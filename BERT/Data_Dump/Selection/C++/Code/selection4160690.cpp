#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)

int selectionSort(int A[], int N){
    int sw = 0, minj;
    for(int i = 0; i < N-1; i++){
        minj = i;
        //
        for(int j = i; j < N; j++){
            if(A[j] < A[minj]){
                minj = j;
            }
        }
        swap(A[i], A[minj]);
        if(i != minj) sw++;
    }
    return sw;
}

int main(){
    int n, A[100], ans;
    cin >> n;
    for(int i = 0; i < n; i++) cin >> A[i];
    ans = selectionSort(A,n);
    //結果の出力
    rep(i,n){
        if(i) cout << " ";
        cout << A[i];
    }
    cout << endl;
    cout << ans << endl;

    return 0;
}
