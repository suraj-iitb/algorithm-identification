#include<bits/stdc++.h>
using namespace std;
int selectionSort(int A[],int n){
    int sw=0;
    for(int i=0;i<n-1;i++){
       int minj=i;
        for(int j=i;j<n;j++){
            if(A[j]<A[minj]){
                minj=j;
               }
        }
           swap(A[i],A[minj]);
             if(i!=minj){sw++;}
         
    }

    return sw;
}
int main(){
    int n;
    cin>>n;
    int A[n];
    for(int i=0;i<n;i++){
        cin>>A[i];
    }
    int sw = selectionSort(A,n);
    for(int i=0;i<n;i++){
        if(i>0){
            cout<<" ";
        }
        cout<<A[i];
    }
    cout<<endl;
    cout<<sw<<endl;
}
