#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n,res; cin>>n;
    vector<int> a(n);
    for(int i=0; i<n; i++) {
        cin>>a[i];
        cout<<a[i]<<(i==n-1 ? '\n' : ' ');
    }
    for(int i=1; i<n; i++) {
        for(int j=0; j<i; j++) {
            if(a[j]>a[i]) {
                res = a[i];
                a.erase(a.begin()+i);
                a.insert(a.begin()+j,res);
                break;
            }
        }
        for(int j=0; j<n; j++) cout<<a[j]<<(j==n-1 ? '\n' : ' ');
    }
}
