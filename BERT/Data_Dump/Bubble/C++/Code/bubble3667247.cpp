#include<iostream>
using namespace std;
int main(){
    int N;
    cin>>N;
    int A[N],i,j,c=0,k;
    for(i=0;i<N;i++) cin>>A[i];
    int flag=1;
    while(flag){
        flag=0;
        for(j=N-1;j>0;j--){
            if(A[j]<A[j-1]){
                k=A[j];
                A[j]=A[j-1];
                A[j-1]=k;
                c++;
                flag=1;
            }
        }
    }
    for(i=0;i<N;i++){
        cout<<A[i];
        if(i!=N-1) cout<<" ";
    }
    cout<<endl;
    cout<<c<<endl;
}
