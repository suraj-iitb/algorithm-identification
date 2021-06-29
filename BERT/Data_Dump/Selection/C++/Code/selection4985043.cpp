#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)


//各計算ステップで最小値を選択していく
int main(){
    int n;
    cin>>n;
    vector<int> a(n);
    rep(i,n){
        cin>>a[i];
    }

    int count = 0;

    rep(i,n-1){
        int minv = i;
        for(int j=i+1;j<n;j++){
            if(a[j]<a[minv]) minv = j;
        }
        if(i!=minv){
            swap(a[i],a[minv]);
            count++;
        }
    }

    rep(i,n){
        cout<<a[i];
        printf("%c",(i==n-1) ? '\n' : ' ');
    }
    cout<<count<<endl;
    return 0;
}
