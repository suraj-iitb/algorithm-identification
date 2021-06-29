#include <bits/stdc++.h>
#include <numeric>
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int selectionsort(int a[],int n){
    int t,sw=0,minj;
    for(int i=0;i<n-1;i++){
        minj=i;
        for(int j=i;j<n;j++){
            if(a[j]<a[minj]) minj=j;
        }
        t=a[i];
        a[i]=a[minj];
        a[minj]=t;
        if(i!=minj) sw++;
    }
    return sw;
}

int main(){
    int a[100];
    int n,sw;
    cin >> n;
    for(int i=0;i<n;i++) cin >> a[i];
    sw=selectionsort(a,n);
    for(int i=0;i<n;i++){
        if(i>0) cout << " ";
        cout << a[i];
    }
    cout << endl;
    cout << sw << endl;
    return 0;
}

