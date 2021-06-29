#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i=0;i<n;i++)cin >> a[i];

    int cou=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n-i-1;j++){
            if(a[j]>a[j+1]){
                swap(a[j],a[j+1]);
                cou++;
            }
        }
    }
    for(int i=0;i<n;i++)cout << a[i] << (i!=n-1?" ":"\n");
    cout << cou << endl;
}

