#include <iostream>
using namespace std;

void trace(int A[],int N){
    for(int i=0;i<N;i++){
        if(i)cout << " ";
        cout << A[i];
    }
    cout << endl;
}

void insertionSort(int A[],int N){
    for(int i=0;i<N;i++){
        int v,j;
        v = A[i];
        j = i-1;
        while(j >=0 && A[j] > v){
            A[j+1] = A[j];
            j--;
            A[j+1]=v;
        }
        trace(A,N);
    }
}

int main(void){
    int n;
    cin >> n;
    
    int arr[n];
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
    
    insertionSort(arr,n);
    
    
}
