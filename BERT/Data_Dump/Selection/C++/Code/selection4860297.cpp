#include <iostream>
#include <algorithm>
using namespace std;

int selectionSort(int a[],int n){
    int minj,count=0;
    for(int i=0;i<n;i++){
        minj=i;
        for(int j=i;j<n;j++){
            if(a[j]<a[minj]){
                minj=j;
            }
        }
        if(a[i]!=a[minj]){
            swap(a[i],a[minj]);
            count++;
        }
    }
    return count;
}

int main(){
    int c,n,a[100];
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    c=selectionSort(a,n);
    for(int i=0;i<n;i++){
        if(i>0)
            cout<<' ';
        cout<<a[i];
    }
    cout<<endl;
    cout<<c<<endl;
}

