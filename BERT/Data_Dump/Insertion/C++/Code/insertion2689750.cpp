#include <string>
#include <iostream>
#include <math.h>
#include <vector>
#include <cstdio>
#include <algorithm>
using namespace std;
void out(int *,int);
int main(){
    int n,a[101],count=1;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    out(a,n);
    while(true){
        if(count==n)break;
        for(int j=count;j>0;j--){
            if(a[j]<a[j-1])swap(a[j],a[j-1]);
        }
        for(int k=0;k<n;){
            cout<<a[k];
            k++;
            if(k!=n)cout<<" ";
        }
        cout<<endl;
        count++;
    }
    return 0;
}

void out(int *line,int n){
    for(int i=0;i<n;++i){
        cout<<line[i];
        if(i+1==n){
            cout<<endl;
        }else{
            cout<<" ";
        }
    }
}
