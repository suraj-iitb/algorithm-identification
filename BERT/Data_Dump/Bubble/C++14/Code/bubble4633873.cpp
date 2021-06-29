#include<iostream>
using namespace std;
int main(){
    int n,v,i,j,k=0,flag=1;
    cin>>n;
    int a[n];
    for(i=0;i<n;i++)cin>>a[i];
    i=0;
    while(flag){
        flag=0;
        for(j=n-1;j>i;j--){
            if(a[j-1]>a[j]){
                v=a[j-1];
                a[j-1]=a[j];
                a[j]=v;
                flag=1;
                k++;
            }
        }i++;
    }
    for(i=0;i<n;i++){
        if(i)cout<<" ";
        cout<<a[i];
    }cout<<endl<<k<<endl;
    return 0;
}
