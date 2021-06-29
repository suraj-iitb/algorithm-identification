#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i=0;i<n;i++)cin >> a[i];

    int mi,mij,cou=0;

    for(int i=0;i<n;i++){
        mi=a[i];
        mij=i;
        for(int j=i;j<n;j++){
            if(mi>a[j]){
                mij=j;
                mi=a[j];
            }
        }
        if(i!=mij){
            swap(a[i],a[mij]);
            cou++;
        }
    }
    for(int i=0;i<n;i++)cout << a[i] << (i!=n-1?" ":"\n");
    cout << cou << endl;
}

