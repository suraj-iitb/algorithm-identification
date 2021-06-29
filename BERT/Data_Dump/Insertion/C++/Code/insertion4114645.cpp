#include<iostream>
using namespace std;

void show(int a[],int n){
    for(int i=0;i<n;i++){
        if(i>0) cout<<' ';
        cout<<a[i];
    }
    cout<<endl;
}

void InsertSort(int a[],int n){
    int i,j,k;
    show(a,n);
    for(i=1;i<n;i++){
        k=a[i];
        for(j=i-1;j>=0&&a[j]>k;j--){
            a[j+1]=a[j];
        }
        a[j+1]=k;
        show(a,n);
    }
}

int main(){
    int n,i;
    int a[101];
    cin>>n;
    for(i=0;i<n;i++)
        cin>>a[i];
    InsertSort(a,n);
    return 0;
}

