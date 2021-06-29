#include<bits/stdc++.h>
using namespace std;

void trace(int a[],int n){
    int i;
    for(i=0;i<n;i++){
        if(i>0)cout<<" ";
        cout<<a[i];
    }
    cout<<endl;
}


void insert(int a[],int n)
{
    int i,j,v;
    for(i=1;i<n;i++){
        v = a[i];
        j = i - 1;
        while(j>=0&&a[j]>v){
            a[j+1]=a[j];
            j--;
        }
        a[j+1] = v;
        trace(a,n);
    }
}

int main(){

    int a[100];
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    trace(a,n);
    insert(a,n);

    return 0;
}

