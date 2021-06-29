#include<bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(n); ++i)
using namespace std;


int selectionSort(int a[], int n) {
    int Min, count = 0, sw_tmp;
    rep(i,n-1) {
        Min = a[i];
        for(int j=i; j<n; ++j) {
            if(a[j] < Min) {
                Min = a[j];
                sw_tmp = j;
            }
        }
            if(a[i] != Min) {
                swap(a[i], a[sw_tmp]);
                count++;
            }
            
        
    }
    return count;
}


int main() {
    int n, a[100], count;
    cin >> n;
    rep(i,n) cin >> a[i];
    count = selectionSort(a, n);
    for(int i=0; i<n; ++i) {
        if(i) {
            cout << " " ;
        }
        cout << a[i];
    }
    cout << endl;
    cout << count << endl;
    
    return 0;
}
