#include<iostream>
#include<algorithm>
using namespace std;

void traceArray(int A[],int N){
    for(int i = 0; i < N; i++){
        if(i > 0){
            cout << " ";
        }
        cout << A[i];
    }
    cout << endl;
}

void insertionSort(int A[],int N){
    for(int i = 1; i < N; i++){
        int v = A[i];
        for(int j = i-1; j >= 0; j--){
            if(v < A[j]){
                A[j+1] = A[j];
                A[j] = v;
            }
        }
        traceArray(A,N);
    }
}

int main(){
    int n;
    cin >> n;
    int a[n];
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    traceArray(a,n);
    insertionSort(a,n);
    return 0;
}
