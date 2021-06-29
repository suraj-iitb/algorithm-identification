#include "bits/stdc++.h"
using namespace std;

void selectionsort(int *n,int *A){
    int count = 0;
    for(int i =0; i<*n; i++){
        int minj = i;
        for(int j=i; j<*n; j++){
            if(A[j]<A[minj]){
                minj = j;
            }
        }
        swap(A[i],A[minj]);
        if(i !=minj)count ++; 
    }
    //出力
    for(int i=0;i<*n-1;i++){
        cout << A[i] << " ";
    }
    cout << A[*n-1] << "\n" << count << "\n";
}

int main(){
    int n; 
    int arr[100];
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    selectionsort(&n,arr);

    return 0;
}
