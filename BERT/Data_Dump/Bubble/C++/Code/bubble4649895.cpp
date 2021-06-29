#include<iostream>
using namespace std;

int main(){
    int n;
    int a[100];
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int count=0;
    bool flag=true;
    while(flag){
        flag=false;
        for(int i=n-1;i>0;i--){
            if(a[i]<a[i-1]){
                int z=a[i];
                a[i]=a[i-1];
                a[i-1]=z;
                flag=true;
                count++;
            }
        }
    }
    for(int i=0;i<n;i++){
        cout<<a[i];
        if(i==n-1)cout<<endl;
        else cout<<' ';
    }
    cout<<count<<endl;
    return 0;
}
