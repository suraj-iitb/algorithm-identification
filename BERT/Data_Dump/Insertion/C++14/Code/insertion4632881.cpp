#include<iostream>
using namespace std;
int main(){
    int n,i,v,j;
    cin>>n;
    int a[n];
    for(i=0;i<n;i++)cin>>a[i];
    for(i=0;i<n;i++){
        if(i!=n-1)
            cout<<a[i]<<" ";
        else if(i==n-1)
            cout<<a[i]<<endl;
        }
    for(i=1;i<n;i++){
        v=a[i];
        j=i-1;
        
        while(j>=0&&a[j]>v){
           a[j+1]=a[j];
           j--;
        }a[j+1]=v;
        
        for(j=0;j<n;j++){
            if(j!=n-1)
                cout<<a[j]<<" ";
            else if(j==n-1)
                cout<<a[j]<<endl;
        }
    }
    return 0;
}
