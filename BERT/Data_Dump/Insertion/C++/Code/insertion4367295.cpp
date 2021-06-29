#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    ll n,a[200];
    cin >> n;
    for(int i=0;i<n;i++) cin >> a[i];
    //print
    for(int k=0;k<n;k++){
        cout << a[k];
        if(k != n-1) cout << " ";
        else cout << endl;
    }
    //insertion sort
    for(int i=1;i<n;i++){
        ll v = a[i];
        int j = i - 1;
        while(j>=0 && a[j] > v){
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = v;
        for(int k=0;k<n;k++){
            cout << a[k];
            if(k != n-1) cout << " ";
            else cout << endl;
        }
    }
    return 0;
}
