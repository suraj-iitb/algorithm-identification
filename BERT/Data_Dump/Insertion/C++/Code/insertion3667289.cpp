#include<iostream>
using namespace std;
int main(){
    int n,A[100]={};
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>A[i];
    }
    int j=0,v;
    for(int i=0;i<n;i++){
         j=i-1;
         v=A[i];
        while(j>=0 && A[j]>v){
            A[j+1]=A[j];
            j-=1;
            A[j+1]=v;
        }
        for(int i=0;i<n-1;i++){
            cout<<A[i]<<" ";
        }
        cout<<A[n-1];
        cout<<endl;
        
    }
   
    return 0;
}
