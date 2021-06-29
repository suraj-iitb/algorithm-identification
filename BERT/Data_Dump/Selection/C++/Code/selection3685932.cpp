#include <iostream>
using namespace std;
int main(void){
    // Your code here!
    int n,A[100]={},count=0,k;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>A[i];
    }
    for(int i=0;i<n;i++){
        int minj=i;
        for(int j=i;j<=n-1;j++){
            if(A[j]<A[minj]){
                minj=j;
            } 
        }
        if(A[i]>A[minj]){
            int tmp=A[i];
            A[i]=A[minj];
            A[minj]=tmp;
            count+=1;   
        }
        
    }
    for(int i=0;i<n;i++){
        if(i>0) cout<<" ";
        cout<<A[i];
    }cout<<endl;
    cout<<count<<endl;
    return 0;
}
    

    
    


