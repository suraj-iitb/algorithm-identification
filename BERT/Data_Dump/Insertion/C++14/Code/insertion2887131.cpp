#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i=0;i<n;i++)cin >> a[i];

    for(int i=0;i<n;i++){
        for(int j=i-1;j>=0;j--){
            if(a[j]>a[j+1])swap(a[j],a[j+1]);
        }
        for(int j=0;j<n;j++){
            cout << a[j];
            cout << (j!=n-1?" ":"\n");
        }
    }
}

