#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    ll n,a[200],count=0;
    cin >> n;
    for(int i=0;i<n;i++) cin >> a[i];
    //bubble sort
    bool flag = true;
    while(flag){
        flag = false;
        for(int i=n-1;i>0;i--){
            if(a[i-1] > a[i]){
                swap(a[i-1], a[i]);
                flag = true;
                count++;
            }
        }
    }
    for(int i=0;i<n;i++){
        cout << a[i];
        if(i != n-1) cout << " ";
        else cout << endl;
    }
    cout << count << endl;
    return 0;
}
