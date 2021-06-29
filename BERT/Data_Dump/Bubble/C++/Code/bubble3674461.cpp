#include <iostream>
using namespace std;
int main(void){
    // Your code here!
    int n,A[100]={},count=0,flag=1;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>A[i];
    }
    int i=0;
    while(flag){
        flag=0;
        for(int j=n-1;j>=i+1;j--){
            if(A[j]<A[j-1]){
                int tmp=A[j-1];
                A[j-1]=A[j];
                A[j]=tmp;
                count+=1;
                flag=1;
            }
        }
        i+=1;
    }
    for(int i=0;i<n;i++){
        if(i>0) cout<<" ";
        cout<<A[i];
    }cout<<endl;
    cout<<count<<endl;
    return 0;
    
}


