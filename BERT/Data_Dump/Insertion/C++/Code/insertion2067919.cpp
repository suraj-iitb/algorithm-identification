#include<iostream>
using namespace std;

int main(){
    int n;
    int A[100];
    cin>>n;
    for(int i=0;i<n;i++) cin>>A[i];
    
    for(int i=0;i<n;i++){
        int v=A[i];
        int j=i-1;    
        
        while(j>=0&&A[j]>v){
            A[j+1]=A[j];
            j--;
        }
        
        A[j+1]=v;
        
        for(int i=0;i<n-1;i++) cout<<A[i]<<" ";
        cout<<A[n-1]<<endl;
    }
}
