#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)

int main(){
    int n;
    cin>>n;
    vector<int> a(n);
    rep(i,n){
        cin>>a[i];
    }
    bool flag = true;
    int count = 0;
    while(flag){
        flag = false;
        rep(i,n-1){
            if(a[i]>a[i+1]){
                swap(a[i],a[i+1]);
                flag = true;
                count++;
            }
        }
    }
    rep(i,n){
        cout<<a[i];
        printf("%c",(i==n-1) ? ' \n' : ' ');
    }
    cout<<count<<endl;
    return 0;
}
