#include<bits/stdc++.h>
using namespace std;

    void insersionsort(int A[100],int N){
        int v,j;
        for(int i=1;i<=N;i++){
            for(int l=0;l<N;l++){
                cout<<A[l];
                if(l!=N-1)  cout<<' ';
                if(l==N-1)  cout<<'\n';
                
            }
            
            v = A[i];
            j = i - 1;
            while(j>=0 && A[j]>v){
                A[j+1] = A[j];  A[j] = v;
                j--;
            }
        }

    }

int main(){
    int N;
    int A[100];

    cin>>N;

    for(int i=0;i<N;i++){
        cin>>A[i];
    }

    insersionsort(A,N);

}
