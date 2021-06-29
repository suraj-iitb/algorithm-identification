#include <bits/stdc++.h>
using namespace std;

int selection(int n,int a[]) {
    int min,cnt=0;
    for(int i=0;i<n;i++) {
        min=i;
        for(int j=i;j<n;j++) {
            if(a[j]<a[min]) {
                min=j;
            }
        }
        swap(a[i],a[min]);
        if(i!=min) {
            cnt++;
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
    ans=selection(n,a);
    for(int i=0;i<n-1;i++) cout<<a[i]<<" ";
    cout<<a[n-1]<<endl;
    cout<<ans<<endl;
    return 0;
}
