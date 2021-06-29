#include <iostream>
#include <cstdio>
using namespace std;

int bubbleSort(int A[],int N){
    int sw=0;
    bool flag=1;  
    for (int i=0; flag; i++) {
        flag=0;
        for (int j=N-1; j>=i+1; j--) {
            if (A[j]<A[j-1]) {
                swap(A[j], A[j-1]);
                flag=1;
                sw++;
            }
        }
    }
    
   
    return sw;
}


int main(int argc, const char * argv[]) {
    int N,sw;
    int A[105];
    cin>>N;
    for (int i=0; i<N; i++) {
        cin >>A[i];
    }
    sw=bubbleSort(A, N);
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

