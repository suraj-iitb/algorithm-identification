#include<iostream>
using namespace std;

int main(){
    int N,count=0;
    cin>>N;
    int A[N];

    for(int i=0;i<N;i++){
        cin>>A[i];
    }

    for(int i=0;i<N;i++){
        int minj=i;
        for(int j=i;j<N;j++){
            if(A[j]<A[minj]){
                minj=j;
            }
        }
        if(minj!=i){
            int k=A[minj];
            A[minj]=A[i];
            A[i]=k;
            count+=1;
        }
        
    }

    for(int i=0;i<N;i++){
        if(i!=N-1){
            cout<<A[i]<<" ";
        }else{
            cout<<A[i]<<endl;
        }
    }
    cout<<count<<endl;

    return 0;
}
