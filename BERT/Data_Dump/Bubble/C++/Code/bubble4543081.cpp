#include<iostream>
using namespace std;

int bubbleSort(int A[], int N){

    int sw = 0;

    for(int i=0; i<N-1; i++){
        for(int j=N-1; j>i; j--){
            if(A[j]<A[j-1]){
                swap(A[j],A[j-1]);
                sw++;
            }
        }
    }
    return sw;
}

int main(){

    int A[110],N,sw;

    cin>>N;
    for(int i=0; i<N; i++)cin>>A[i];

    sw = bubbleSort(A,N);

    for(int i=0; i<N-1; i++)cout<<A[i]<<' ';
    cout<<A[N-1]<<endl;
    cout<<sw<<endl;

    return 0;
}

