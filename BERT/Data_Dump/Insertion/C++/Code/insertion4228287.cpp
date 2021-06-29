#include <bits/stdc++.h>
using namespace std;
 
void trace(int a[],int N){
    int i;
    for(i=0;i<N;i++){
        if(i>0)cout<<" ";
        cout<<a[i];
    }
    cout<<endl;
}

void insertionsort(int a[],int N){
    int v,j;
    for(int i=1;i<N;i++){
        v=a[i];
        j=i-1;
        while(j>=0&&a[j]>v){
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=v;
        trace(a,N);
    }
}

int main(){ 
    int n;
    cin>>n;

    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    trace(a,n);
    insertionsort(a,n);

    return 0;
}
