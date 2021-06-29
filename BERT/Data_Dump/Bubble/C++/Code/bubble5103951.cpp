//バブルソート bubble sort
#include "bits/stdc++.h"
using namespace std;
void bubblesort(int *n,int *A){
    int flag = 1;
    int count = 0;
    while(flag){
        flag = 0;
        for(int j=*n-1; j>0; j--){
           if(A[j] < A[j-1]){
            swap(A[j],A[j-1]);
            count ++;
            flag = 1;
            }
        }
    }
    for(int j=0; j<*n-1; j++){
        cout << A[j] << " ";
    }
    cout << A[*n-1] << "\n" << count <<"\n";
}
int main(){
    int n;
    cin >> n;
    int A[100];
    
    for(int j=0;j<n;j++){
        cin >> A[j];
    }
    bubblesort(&n,A);

    return 0;
}
