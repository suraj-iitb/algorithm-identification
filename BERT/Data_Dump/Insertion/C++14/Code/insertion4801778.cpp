#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); ++i)
using ll = long long;

void printarray(vector<int> a){
    rep(i,a.size()){
        cout << a[i];
        if(i!=a.size()-1) cout << " ";
        else cout << endl;
    }
}

void insertionSort(vector<int> &a, int n){
    rep(i,n){
        int v = a[i];
        int j = i - 1;
        while(j>=0 && a[j]>v){
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = v;
        printarray(a);
    }
}

int main(){
    int n; cin >> n;
    vector<int> a(n);
    rep(i,n) cin >> a[i];

    insertionSort(a,n);
}
