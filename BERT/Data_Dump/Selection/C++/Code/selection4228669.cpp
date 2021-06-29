#include <bits/stdc++.h>
using namespace std;
 
int selectionsort(int a[],int n){
    int sw=0,minj;
    for(int i=0;i<n-1;i++){
        minj=i;
        for(int j=i+1;j<n;j++){
            if(a[minj]>a[j])minj=j;
        }
        swap(a[i],a[minj]);
        if(i!=minj)sw++;
    }

    return sw;
}
int main(){ 
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }

    int sw;
    sw=selectionsort(a,n);
    for(int i=0;i<n;i++){
        if(i>0)cout<<" ";
        cout<<a[i];
    }
    cout<<endl;

    cout<<sw<<endl;
 
    return 0;
}
