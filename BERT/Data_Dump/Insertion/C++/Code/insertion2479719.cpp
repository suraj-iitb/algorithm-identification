#include <algorithm>
#include <iostream>
#include <stdio.h>

//?????\?????????

const int MAX = 100;

using namespace std;

//?????????????´?????????????????????????
void trace(int a[],int n){
    for (int i=0;i<n;i++){
        if(i>0){cout << " ";}
        cout << a[i];
    }
    cout << endl;
}

void InsertionSort(int A[],int n){
    int v,j;
    for (int i=1; i<n; i++){
        v=A[i];
        j=i-1;
        while(j>=0 && A[j]>v){
            A[j+1] = A[j];
            j--;
        }
        A[j+1]=v;
        trace(A, n);
    }
}

int main(){
    int A[MAX], n;
    cin >> n;
    for(int i=0;i<n;i++){
    scanf("%d", &A[i]);
    }
    trace(A,n);
    InsertionSort(A, n);
    return 0;
}
