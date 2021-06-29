#include <iostream>
using namespace std;

void print(int A[],int N){
    for(int i=0; i < N;i++){
        if(i != N-1)cout << A[i] << " ";
        else cout << A[i];   
    }
    cout << endl;
}

int  selectionSort(int A[],int N){
    int sw = 0;
    int minj;
    int j,i = 0;
    for(i = 0;i < N-1;i++){
        minj = i;
        for(j = i;j < N;j++){
            if(A[j] < A[minj])minj = j;
        }
        swap(A[i],A[minj]);
        if(i != minj)sw++;
        //print(A,N);
    }
    print(A,N);
    return sw;
    
}

int main(void){
    // Your code here!
    int A[1001];
    int n;
    
    cin >> n;
    for(int i = 0;i < n; i++)cin >> A[i];
    
    int cnt = selectionSort(A,n);
    cout << cnt << endl;
    return 0;
}


