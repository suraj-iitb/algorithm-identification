#include<iostream>
using namespace std;

int main(void){

    int n ;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)cin>>a[i];
    for(int k=0;k<n;k++){
            cout<<a[k];
            if(k!=n-1)cout<<' ';
            if(k==n-1)cout<<endl;
        }
    for(int i=1;i<n;i++){
        for(int j=i;j>=0&&a[j]<a[j-1];j--){
            int tmp = a[j];
            a[j]=a[j-1];
            a[j-1]=tmp;
        }
        for(int k=0;k<n;k++){
            cout<<a[k];
            if(k!=n-1)cout<<' ';
            if(k==n-1)cout<<endl;
        }
    }

    return 0;
}
