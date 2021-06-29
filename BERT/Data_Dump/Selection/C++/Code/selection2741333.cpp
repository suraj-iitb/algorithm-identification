#include <iostream>
#include <stdio.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (n); ++i)

int selectionSort(int A[], int N){
    int sw = 0;
    rep(i, N - 1){
        int minj = i;
        for(int j = i; j < N; ++j){
            if(A[j] < A[minj]) 
                minj = j;
        }
        if(i != minj){
            swap(A[i], A[minj]);
            ++sw;
        }
    }
    return sw;
}

int main(void){
    int N;    cin >> N;
    int A[N]; rep(i, N) cin >> A[i];
    
    int sw = selectionSort(A, N);
    
    rep(i, N - 1) cout << A[i] << " ";
    cout << A[N - 1] << endl;
    cout << sw << endl;
    
    return 0;
}
