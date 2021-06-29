#include<iostream>
using namespace std;

int selectionSort(int A[], int N){
    int minj;
    int x= 0;
    int a;
    for(int i = 0; i < N-1; i++){
        minj = i;
        for(int j = i; j<N; j++){
            if (A[j] < A[minj]) minj = j;
        }
        a = A[i]; A[i] = A[minj]; A[minj] = a;
        if(i != minj) x++;
    }return x;
}
int main(){
    int x;
    int N;
    int A[1000];
    cin >>N;
    for (int i = 0; i < N; i++){
        cin >>A[i];
    }
    
    x = selectionSort(A, N);
    for(int i = 0; i < N; i++){
        cout <<A[i];
        if(i!=N-1){
            cout<<" ";
        }
        else cout<<endl;
    }
    cout <<x <<endl;
    return 0;
}


