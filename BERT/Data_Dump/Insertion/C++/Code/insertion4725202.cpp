#include <bits/stdc++.h>
#include<iostream>
#include<algorithm>
using namespace std;

int main() {
    int n;
    int a[1000]={};
    int v;
    int i;
    int j;
    int k;
    cin>>n;
    for(i=0;i<n;i++){
        cin>>a[i];
    }
    for(i=0;i<n;i++){
        if(i>0){cout<<" ";}
        cout<<a[i];
    }
        cout<<endl;
    for(i=1;i<n;i++){
        v=a[i];
        j=i-1;
        while(j>=0&&a[j]>v){
            a[j+1]=a[j];
            j--;
            a[j+1]=v;
        }
        for(k=0;k<n;k++){
        if(k>0){cout<<" ";}
        cout<<a[k];
        }
        cout<<endl;
    }
    return 0;
}
