#include <iostream>
using namespace std;
int main(void){
    int n,j,temp,cnt;
    cin>>n;
    int A[n];
    for(int i=0;i<n;i++){
        cin>>A[i];
    }
    cnt=0;
    j=0;
    while(j<n-1){
        for(int i=n-1;i>j;i--){
            if(A[i]<A[i-1]){
                temp=A[i];
                A[i]=A[i-1];
                A[i-1]=temp;
                cnt++;
            }
        }
        j++;
    }
    
    for(int i=0;i<n;i++){
        cout<<A[i];
        if(i==n-1)cout<<endl;
        else cout<<' ';
    }
    cout<<cnt<<endl;
    return 0;
}

