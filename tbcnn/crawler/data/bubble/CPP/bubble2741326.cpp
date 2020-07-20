#include <iostream>
#include <stdio.h>
using namespace std;
#define rep(i,n) for (int i=0;i<(n);i++)

int bubbleSort(int A[], int N){
    int sw = 0;
    bool flag = true;
    int i = 0;
    while(flag){
        flag = false;
        for(int j = N - 1; j >= i + 1; --j){
            if(A[j] < A[j - 1]){
                swap(A[j], A[j - 1]);
                flag = true;
                ++sw;
            }
        }
        ++i;
    }
    return sw;
}

int main(void){
    int N;    cin >> N;
    int A[N]; rep(i, N) cin >> A[i];
    
    int sw = bubbleSort(A, N);
    
    rep(i, N - 1) cout << A[i] << " ";
    cout << A[N - 1] << endl;
    cout << sw << endl;
    
    return 0;
}
