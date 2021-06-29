#include<iostream>
using namespace std;

int main(){
    int n;cin>>n;int A[n];for(int i=0;i<n;i++)cin>>A[i];
    bool flg=1;
    int cnt=0;
    while(flg){
        flg=0;
        for(int j=n-1;j>0;j--){
            if(A[j]<A[j-1]){
                int tmp=A[j];
                A[j]=A[j-1];
                A[j-1]=tmp;
                flg=1;
                cnt+=1;
            }
        }
    }
    for(int i=0;i<n;i++){if(i==n-1)cout<<A[i]<<endl;else{cout<<A[i]<<' ';}}
    cout<<cnt<<endl;
    return 0;
}
