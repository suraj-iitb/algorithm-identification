#include <iostream>
using namespace std;
int A[100000]={};
int k,key;
void sort(int n){
    for(int j=1;j<=n;j++){
        key=A[j];
        k=j-1;
        while(k>0 && A[k]>key){
            A[k+1]=A[k];
            k=k-1;
        }
        A[k+1]=key;
        for(int l=1;l<=n;l++){
            if(l==n){
                cout<<A[l];
            }
            else{
                cout<<A[l]<<" ";
            }
        }
        cout<<endl;
    }
}
int main(){
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>A[i];
    }
    sort(n);
    return 0;
}
