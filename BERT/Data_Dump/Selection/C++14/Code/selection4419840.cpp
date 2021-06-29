#include <bits/stdc++.h>
using namespace std;

int selectionSort(int A[],int N);

int main(){
    int N,ans;
    cin>>N;
    int A[N];

    for(int i=0;i<N;i++){
        cin>>A[i];

    }

    ans=selectionSort(A,N);

    for(int i=0;i<N-1;i++){
        cout<<A[i]<<" ";
    }
    cout<<A[N-1]<<endl;
    cout<<ans<<endl;
    
    return 0;
}

int selectionSort(int A[],int N){
    int minv;
    int ind,sw=0;
    for(int j=0;j<N-1;j++){
        minv=A[j];
        ind=j;
        for(int i=j+1;i<N;i++){

            if(A[i]<minv){
                minv=A[i];
                ind=i;
            }
        }
        if(ind!=j){
            swap(A[j],A[ind]);
            sw++;
        }
    }
    return sw;
}
