#include <iostream>
using namespace std;

void output(int A[], int N, int W){
    
    for (int i=0; i<N; i++){
        if (i==N-1)
        {
            cout << A[i] << endl;
            cout << W << endl;
        }
        else
        {
            cout << A[i] << flush;
            cout << " " << flush;
        }
    }
}

int serch(int A[],int N,int X){
    
    int MIN,minj;
    
    MIN=A[X];
    minj=X;
    
    for (int j=X; j<N; j++){
        if (A[j]<MIN){
            MIN=A[j];
            minj=j;
        }
    }
    return minj;
}

int selection(int A[],int N){
    
    int minj,W,X;
    
    W=0;
    for (int i=0; i<N-1; i++){
         X=i;
         minj=serch(A, N, X);
         if (A[minj]<A[i]){
             swap(A[minj], A[i]);
             W++;
         }
    }
    return W;
}

int main() {
    
    int N,W;
    int A[100];
    
    cin >> N;
    
    for (int i=0; i<N; i++){
        cin >> A[i];
    }
    
    W=selection(A, N);
    output(A, N, W);
    
    return 0;
}
