#include<bits/stdc++.h>
using namespace std;
int *insertionsort(int n,int* A){
    for(int i=n;i>0;i--){
        if (i != 1){
            cout<<A[n-i]<<" ";
        }else{
            cout<<A[n-1]<<endl;
        }
    }
    for(int a=1;a<n;a++){
        for(int b=a-1;b>=0;b--){
            if(A[b+1]<A[b]){
                int v = A[b+1];
                A[b+1]=A[b];
                A[b]=v;
            }else{
                break;
            }
        }
        for(int i=n;i>0;i--){
        if (i != 1){
            cout<<A[n-i]<<" ";
        }else{
            cout<<A[n-1]<<endl;
        }
    }
    }
    int *outputs=new int[n];
    outputs = A;
    return outputs;
}
int main(){
    int n;
    cin>>n;
    int unsorted[n];
    for (int v=n;v>0;--v){
        cin>>unsorted[n-v];
    }
    int *sortok=new int[4];
    sortok=insertionsort(n,unsorted);
    return 0;
}
