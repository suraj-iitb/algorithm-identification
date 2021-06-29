#include <iostream>
using namespace std;

void show(int a[],int n){
    
    for(int i=0;i<n;i++){
        if(i>0)
            cout<<' ';
        cout<<a[i];
    }
    cout<<endl;
}

void insertionSort(int a[],int n){
    int j,i,v;
    for(int i=1;i<n;i++){
        v=a[i];
        j=i-1;
        while(j>=0&&a[j]>v){
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=v;
        show(a,n);
    }
}

int main(){
    int n,a[100];
    
    cin>>n;
    
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    
    show(a,n);
    insertionSort(a,n);
}

