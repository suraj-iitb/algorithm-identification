#include<iostream>
using namespace std;
int main(){
    int a[100],num=0,n,b;
    cin>>n;
    for(int i =0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<n;i++){
        int mini=i;
        for(int j=i+1;j<n;j++){
            if(a[j]<a[mini]){
                mini=j;
            }
        }
        if(a[i]!=a[mini]){
            b=a[i];
            a[i]=a[mini];
            a[mini]=b;
            num++;
        }
    }
    for(int i=0;i<n;i++){
        cout<<a[i];
        if(i!=n-1){
            cout<<' ';
        }
    }
    cout<<endl<<num<<endl;
    return 0;
}

