#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

int selectionSort(int A[],int N){
    int i,j,minj,sw = 0;
    for (i=0; i<N; i++) {
        minj=i;
        for (j=i; j<N; j++) {
            if (A[j]<A[minj]) {
                minj=j;
            }
        }
        swap(A[i], A[minj]);
        if (i!=minj) {
            sw++;
        }
    }
    return sw;
}




int main(int argc, const char * argv[]) {
    int A[105],N,i,sw;
    cin >>N;
    for (i=0; i<N; i++) {
        cin >>A[i];
    }
    sw=selectionSort(A, N);
    for (int i=0; i<N; i++) {
        if (i<N-1) {
            cout <<A[i]<<" ";
        } else {
            cout <<A[i]<<endl;
        }
    }
    cout <<sw<<endl;
    
    
    return 0;
}

