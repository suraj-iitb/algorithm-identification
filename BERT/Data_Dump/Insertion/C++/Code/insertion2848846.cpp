#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int a[110];

int main(){
    int n,v,j;
    cin>>n;
    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=1;i<n;i++){
        for(int o=0;o<n;o++){
            if(o==n-1) cout<<a[o]<<endl;
            else cout<<a[o]<<" ";
        }
        v=a[i];
        j=i-1;
        while(j>=0&&a[j]>v){
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=v;
    }
    for(int o=0;o<n;o++){
        if(o==n-1) cout<<a[o]<<endl;
        else cout<<a[o]<<" ";
    }
    return 0;
}

