#include<bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(n); ++i)
//#define rep(i,n) for(int i=0; i<(n); ++i)
using namespace std;



void trace(vector<int>&a, int n) {
    for(int i=0; i<n; ++i) {
        if(i > 0) printf(" ");
        printf("%d", a[i]);
    }
    printf("\n");
}

void insertSort(vector<int>&a, int n) {
    for(int i=1; i<n; ++i) {
        int v = a[i];
        int j=i-1;
        while(j>=0 && a[j]>v) {
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = v;
        trace(a, n);
    }
}

int main() {
    int n;
    cin >> n;
    vector<int>a(n);
    rep(i,n) cin >> a[i];
    //rep(i,n); cin >> a[i];
    
    trace(a, n);
    insertSort(a, n);
    
    return 0;
}

