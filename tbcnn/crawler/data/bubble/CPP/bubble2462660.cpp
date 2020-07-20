#include <bits/stdc++.h>
using namespace std;

int bubble(int n,int a[]) {
    int cnt=0;
    for(int i=0;i<n;i++) {
        for(int j=n-1;j>i;j--) {
            if(a[j]<a[j-1]) {
                swap(a[j],a[j-1]);
                cnt++;
            }
        }
    }
    return cnt;
}

int main() {
    int n;cin>>n;
    int a[100];
    for(int i=0;i<n;i++) {
        cin>>a[i];
    }
    int ans=0;
    ans=bubble(n,a);
    for(int i=0;i<n-1;i++) {
        cout<<a[i]<<" ";
    }
    cout<<a[n-1]<<endl;
    cout<<ans<<endl;
    return 0;
}
