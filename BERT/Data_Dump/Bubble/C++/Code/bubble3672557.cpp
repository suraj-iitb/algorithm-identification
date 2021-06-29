#include<iostream>
#include<stdio.h>
using namespace std;


int bubbleSort(int A[],int N){
    int flag=1,j;
    int sw=0;
    while(flag){
        flag=0;
        for(j=N-1;j>=1;j--){
            if(A[j]<A[j-1]){
                swap(A[j],A[j-1]);
                sw++;
                flag=1;
            }
        }
    }
return sw;
}

int main(){
    int A[100],N,sw;
    cin>>N;
    for(int i=0;i<N;i++) cin>>A[i];
    
    sw=bubbleSort(A,N);

    for(int i=0;i<N;i++){
        if(i) cout<<" ";
        cout<<A[i];
    }
    cout<<endl;
    cout<<sw<<endl;
    
    return 0;
}


