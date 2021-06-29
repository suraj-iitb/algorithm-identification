#include<iostream>
#include<string>
#include<stdio.h>
using namespace std;
int bub(int a[],int n){
    int count=0;
    bool f=1;
    for(int i=0;f;i++){
        f=0;
        for(int k=n-1;k>=i+1;k--){
            if(a[k]<a[k-1]){
                swap(a[k],a[k-1]);
                f=1;
                count++;
            }
        }
    }
    return count;
}
int main(){
    int i,k,n,count;
    int a[100];
    
    cin>>n;
    for(i=0;i<n;i++)cin>>a[i];

    count=bub(a,n);
    
    for(int i=0;i<n;i++){
        if(i>0)cout<<" ";
        cout<<a[i];
    }
    cout<<endl;
    cout<<count<<endl;
    
    return 0;
        
}
    


