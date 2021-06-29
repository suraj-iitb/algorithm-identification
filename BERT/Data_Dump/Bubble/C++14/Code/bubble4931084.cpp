#include<iostream>
using namespace std;

int main(){
    int N,count=0;
    cin>>N;
    int A[N];
    int flag=1;

    for(int a=0;a<N;a++){
        cin>>A[a];
    }

    while(flag==1){
        flag=0;
        for(int j=N-1;j>=1;j--){
            if(A[j]<A[j-1]){
                int k=A[j];
                A[j]=A[j-1];
                A[j-1]=k;
                count+=1;
                flag=1;
            }
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
