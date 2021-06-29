#include<iostream>
using namespace std;

void insertionSort(int* A, int N){
    int i,v,j,t;
    for(i=0;i<N;i++){
        v = A[i];
        j = i - 1;
        while (j >= 0 and A[j] > v){
           A[j+1] = A[j];
           j-=1;
           A[j+1] = v;
        }
        
        for(t=0;t<N-1;t++){
            cout<<A[t]<<" ";
        }
        cout<<A[N-1]<<endl;
    }
}
int main(){
    int A[1000];
    int k,N;
    cin>>N;
    for(k=0;k<N;k++){
        cin>>A[k];
    }
    insertionSort(A,N);
    
}
