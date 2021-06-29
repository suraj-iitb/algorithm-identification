#include <iostream>
using namespace std;
//#define swap(x,y) {int tmp=x;x=y;y=tmp;}

int bubbleSort(int a[],int n){
    int flag=1,count=0;
    while(flag){
        flag=0;
        for(int j=n-1;j>=1;j--){
            if(a[j]<a[j-1]){
                swap(a[j],a[j-1]);
                flag=1;
                count++;
            }
        }
    }
    return count;
}

int main(){
    int n,a[100];
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    
    int c=bubbleSort(a,n);
    
    for(int i=0;i<n;i++){
        if(i>0)
            cout<<' ';
        cout<<a[i];
    }
    cout<<endl;
    cout<<c<<endl;
}

