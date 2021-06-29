#include<iostream>
using namespace std;

int bubbleSort(int A[], int N){
    int sw=0;
    int flag=1;
    while(flag){
        flag=0;
        for(int i=N-1;i>0;i--){
            if(A[i]<A[i-1]){
                swap(A[i],A[i-1]);
                flag=1;
                sw++;
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
        if(i != 0) cout<<" ";
        cout<<A[i];
    }
    cout<<endl;
    cout<<sw<<endl;
    
    return 0;
}
