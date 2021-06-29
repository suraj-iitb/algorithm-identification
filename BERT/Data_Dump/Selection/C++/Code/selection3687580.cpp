#include<iostream>
#include<string>
#include<stdio.h>
using namespace std;

int selection(int a[],int n){
    int count=0,min;
    for(int i=0;i<n-1;i++){
        min=i;
        for(int j=i;j<n;j++){
            if(a[j]<a[min])min=j;
        }
        int t=a[i];a[i]=a[min];a[min]=t;
        if(i!=min)count++;
    }
    return count;
}

int main(){
    int a[100],n,i,count;
    
    cin>>n;
    for(i=0;i<n;i++)cin>>a[i];
    
    count=selection(a,n);
    
    for(i=0;i<n;i++){
        if(i>0)cout<<" ";
        cout<<a[i];
    }
    cout<<endl;
    cout<<count<<endl;
    
    return 0;
}
