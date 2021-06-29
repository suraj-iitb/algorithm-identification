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

int trace(int A[],int N){

    int j,V,W;
    
    j=0;
    W=0;
    while (j!=N-1){
          for (int i=N-1; i>j; i--){
              if (A[i-1]>A[i]){
                  V=A[i];
                  A[i]=A[i-1];
                  A[i-1]=V;
                  W++;
              }
          }
          j++;
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
    
    W=trace(A, N);
    output(A, N, W);
    
    return 0;
}
