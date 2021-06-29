#include<iostream>
using namespace std;
int selectionSort(int* A,int N){ // N個の要素を含む0-オリジンの配列A
   int minj,k=0,j,i,v;
   for(i=0;i<N;i++){
       minj = i;
       for(j=i;j<N;j++){
            if(A[j] < A[minj]){
            minj = j;
            }
       }
        v=A[i];
        A[i]=A[minj];
        A[minj]=v;
        if(minj!=i){
            k+=1;
        }
    }
    return k;
}
int main(){
    int N,i,k;
    int A[1000];
    cin>>N;
    for(i=0;i<N;i++){
        cin>>A[i];
    }
    k=selectionSort(A,N);
    for(i=0;i<N-1;i++){
        cout<<A[i]<<" ";
    }
    cout<<A[N-1]<<endl;
    cout<<k<<endl;
    return 0;
}
