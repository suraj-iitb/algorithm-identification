#include<iostream>
using namespace std;
int main(){
    int a[100],n,b,num=0;
    cin>>n;
    for(int i =0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<n;i++){
        for(int j=n-1;j>=i+1;j--){
            if(a[j]<a[j-1]){
                b=a[j];a[j]=a[j-1];a[j-1]=b;
                num++;
            }
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

