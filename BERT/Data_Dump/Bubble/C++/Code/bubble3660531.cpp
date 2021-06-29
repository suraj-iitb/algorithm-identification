#include<iostream>
#include<string.h>
#define loop(i,a,b) for(int i=(a);i<(b);++i)
#define rep(i,b) loop(i,0,b)
using namespace std;
int main(){
    bool flag=1;
    int temp,n;
    int A[101];
    int c=0;
    int i=0;
    cin>>n;
    rep(i,n){
        cin>>A[i];
    }
    while(flag){
        flag=0;
        for(int j=n-1;j>0;j--){
            if(A[j]<A[j-1]){
                temp=A[j];
                A[j]=A[j-1];
                A[j-1]=temp;
                flag=1;
                c+=1;
            }
        }
    }
    rep(i,n){
        if(i==0) cout<<A[i];
        else cout<<" "<<A[i];
    }
    cout<<endl<<c<<endl;
}


