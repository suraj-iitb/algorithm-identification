#include<iostream>
using namespace std;
int main(){
    int N;
    cin>>N;
    int A[N];
    for(int i=0;i<N;i++){
        cin>>A[i];
    }
    for(int i=1;i<N;i++){
        int v=A[i];
        int j=i-1;
        for(int k=0;k<N-1;k++){
            cout<<A[k]<<" ";
        }cout<<A[N-1]<<endl;
        
        while(j>=0 && A[j]>v){
            int B=A[j+1];
            A[j+1]=A[j];
            A[j]=B;
            j--;
        }
        A[j+1]=v;
    }
    for(int i=0;i<N-1;i++){
        cout<<A[i]<<" ";
    }cout<<A[N-1]<<endl;
    return 0;
}

