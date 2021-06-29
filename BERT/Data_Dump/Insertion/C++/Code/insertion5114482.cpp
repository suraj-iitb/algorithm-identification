#include <iostream>
using namespace std;

void print(int A[],int N){
    for(int i=0; i < N;i++){
        if(i != N-1)cout << A[i] << " ";
        else cout << A[i];   
    }
    cout << endl;
}

void insertionSort(int A[],int N){
    int i,v,j;
    for( i= 1;i < N;i++){
        v = A[i];
        j = i-1;
        while(j >= 0 && A[j] > v){
            A[j+1] = A[j];
            j--;
        }
        A[j+1] = v;
        print(A,N);
    }
}

int main(void){
    // Your code here!
    int A[1001];
    int n;
    
    cin >> n;
    for(int i = 0;i < n; i++)cin >> A[i];
    print(A,n);
    insertionSort(A,n);
    return 0;
}


