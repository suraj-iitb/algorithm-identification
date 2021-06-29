#include<iostream>

using namespace std;

int main(){
    int n,work;
    cin>>n;
    int* a=new int[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<n - 1;i++){
        cout<<a[i]<<" ";
    }
    cout<<a[n-1]<<"\n";
    for(int i=1;i<n;i++){
        work=a[i];
        int j=i-1;
        while(j>=0 && a[j]>work){
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=work;
        for(int j=0;j<n-1;j++){
            cout<<a[j]<<" ";
        }
        cout<<a[n-1]<<"\n";
    }
}
