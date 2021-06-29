#include <bits/stdc++.h>
#include <numeric>
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//flagを用いたソート
int bubblesort(int a[],int n){
    int sw=0;
    bool flag=1;
    for(int i=0;flag;i++){
        flag=0;
        for(int j=n-1;j>=i+1;j--){
            if(a[j]<a[j-1]){
                //隣接要素を交換する
                swap(a[j],a[j-1]);
                flag=1;
                sw++;
            }
        }
    }
    return sw;
}

int main(){
    int a[100],n,sw;
    cin >> n;
    for(int i=0;i<n;i++) cin >> a[i];
    sw=bubblesort(a,n);
    for(int i=0;i<n;i++){
        if(i) cout << " ";
        cout << a[i];
    }
    cout << endl;
    cout << sw << endl;
    return 0;
}

