#include<iostream>
using namespace std;
int n;
int a[2000000];
int out[2000001];
int c[10001]={0};
int main(){
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
        c[a[i]]++;
    }
    for(int i=0;i<10000;i++){
        c[i+1]=c[i]+c[i+1];
    }
    for(int i=n;i>=0;i--){
        out[(c[a[i]]--)]=a[i];
    }
    for(int i=1;i<n;i++)
        cout<<out[i]<<" ";
    cout<<out[n]<<endl;
    return 0;
}

