#include <iostream>
#include <stdio.h>
#include <string>
#include <cmath>
using namespace std;

int main() {
    int i,n;
    cin>>n;
    int a[n];
    int b[10000];
    for(i=0;i<n;i++){
        cin>>a[i];

    }

    for (i = 0; i < 10000; ++i) {
        b[i]=0;
    }

    for (i = 0; i < n; ++i) {
        b[a[i]]++;
    }

    for (i = 1; i < 10000; ++i) {
        b[i]=b[i]+b[i-1];
    }

    int c[n];
    for (i = n-1; i >=0; --i) {
        c[b[a[i]]-1]=a[i];
        b[a[i]]--;

    }

    for (i = 0; i < n; ++i) {
       if(i !=0)cout<<" ";
        cout<<c[i];
    }

cout<<endl;


    return 0;
}
