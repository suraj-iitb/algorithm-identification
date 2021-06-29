#include <bits/stdc++.h>
using namespace std;

int bubblesort(int A[],int N);

int main(){
    int N,ans;
    cin>>N;
    int A[N];

    for(int i=0;i<N;i++){
        cin>>A[i];
    }
    ans=bubblesort(A,N);
    for(int i=0;i<N-1;i++){
        cout<<A[i]<<" ";
    }
    cout<<A[N-1]<<endl;
    cout<<ans<<endl;

    return 0;
}

int bubblesort(int A[],int N){
    int sw=0;
    int j=0;
    while(j!=N-1){
        for(int i=N-1;i!=j;i--){
            
            if(A[i]<A[i-1]){
                int tmp;
                tmp=A[i];
                A[i]=A[i-1];
                A[i-1]=tmp;
                
                sw++;
            }
        }
        j++;
    }
    return sw;
}
