#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(n); i++)
using namespace std;

int cnt = 0;
int L[500500], R[500500];


void merge(vector<int>& a, int l, int m, int r){
    int n1 = m - l;
    int n2 = r - m;
    rep(i, n1) L[i] = a[l+i];
    rep(i, n2) R[i] = a[m+i];
    L[n1] = 1e9+10;
    R[n2] = 1e9+10;
    int i, j;
    i = 0; j = 0;
    for (int k=l; k<r; k++){
        cnt++;
        if (L[i]<=R[j]) a[k] = L[i++];
        else a[k] = R[j++];
    }
}



void mergesort(vector<int>& a, int left, int right){
    if (right - left > 1){
        int mid = (left + right)/2;
        mergesort(a, left, mid);
        mergesort(a, mid, right);
        merge(a, left, mid, right);
    }
}

int main(){
    int n; cin >> n;
    vector<int> a(n);
    rep(i, n) cin >> a[i];
    mergesort(a, 0, n);
    rep(i, n){
        if (i) cout << " ";
        cout << a[i];
    }
    cout << endl;
    cout << cnt << endl;
}
