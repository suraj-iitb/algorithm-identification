#include<iostream>
using namespace std;
int bubbleSort(int* A, int N){ 
    int flag,v,j,k=0;
    flag = 1;
    while(flag==1){
        flag = 0;
        for(j=N-1;j>0;j--){
           if(A[j] < A[j-1]){
               v=A[j];
               A[j]=A[j-1];
               A[j-1]=v;
               flag = 1;
               k+=1; 
            }
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
    k=bubbleSort(A,N);
    for(i=0;i<N-1;i++){
        cout<<A[i]<<" ";
    }
    cout<<A[N-1]<<endl;
    cout<<k<<endl;
    return 0;
}
