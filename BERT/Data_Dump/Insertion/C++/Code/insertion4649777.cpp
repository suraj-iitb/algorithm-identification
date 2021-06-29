#include<iostream>
using namespace std;

int main(){
    int n;
    int a[100];
    
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<n;i++){
        cout<<a[i];
        if(i==n-1) cout<<endl;
        else cout<<' ';
    }
    for(int i=1;i<n;i++){
        int j=i-1;
        int key=a[i];
        while(j>=0 && a[j]>key){
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=key;
        for(int i=0;i<n;i++){
        cout<<a[i];
        if(i==n-1)cout<<endl;
        else cout<<' ';
    }
}
}
