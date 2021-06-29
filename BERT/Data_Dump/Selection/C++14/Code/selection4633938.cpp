#include<iostream>
using namespace std;
int main(){
    int n,i,j,minj,max,counter=0;
    cin>>n;
    int a[n];
    for(i=0;i<n;i++)cin>>a[i];
    for(i=0;i<n-1;i++){
        minj=i;
        for(j=i+1;j<n;j++)if(a[minj]>a[j])minj=j;
        if(a[i]>a[minj]){
            max=a[i];
            a[i]=a[minj];
            a[minj]=max;
            counter++;
        }
    }
    for(i=0;i<n;i++){
        if(i)cout<<" ";
        cout<<a[i];
    }cout<<endl<<counter<<endl;
    return 0;
}
