#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;

int n;
vector<int> a(100);

void insertionSort(vector<int> a, int n){
    for (int i = 1; i<n; i++){
        int v = a[i];
        int j = i-1;
        while (j >= 0 && a[j] > v){
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = v;
        rep(j, n-1){
            cout << a[j] << " ";
        }
        cout << a[n-1] <<endl;
    }
}

int main(){
    cin>>n;
    rep(i, n) cin>>a[i];
    rep(i, n-1){
        cout << a[i] << " ";
    }
    cout << a[n-1] <<endl;
    insertionSort(a, n);
    return 0;
}
