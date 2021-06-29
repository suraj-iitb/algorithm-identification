#include<iostream>
using namespace std;
int main(){
    int count=0,minj,n,temp,A[100];
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>A[i];
    }
    for(int i=0;i<n;i++){
        minj=i;
        for(int j=i;j<n;j++){
            if(A[j]<A[minj]){
                minj=j;
            }
        }
    if(i!=minj){
        temp=A[minj];
        A[minj]=A[i];
        A[i]=temp;
        count+=1;
    }
    }
    for(int i=0;i<n;i++){
        if(i==0)cout<<A[i];
        else cout<<" "<<A[i];
    }
    cout<<endl<<count<<endl;
}
