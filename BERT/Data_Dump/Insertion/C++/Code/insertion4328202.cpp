#include<bits/stdc++.h>
#define ll long long 
#define P pair<int,int>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;

void out(vector<int> a,int n){
    rep(j,n){
        cout << a[j];
        if(j!=n-1) cout << " ";
    }
    cout << endl;
}

void insertionSort(vector<int> a,int n){
    out(a,n); 
    for(int i=1;i<n;i++){
        int v = a[i];
        int j = i-1;
        while(j>=0 && a[j]>v){
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = v;
        out(a,n);
    }
}


int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i,n) cin >> a[i];
    insertionSort(a,n);
    return 0;
}
