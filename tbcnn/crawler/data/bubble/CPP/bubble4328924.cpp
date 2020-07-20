#include<bits/stdc++.h>
#define ll long long 
#define P pair<int,int>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;

void out(vector<int> a,int n){
    rep(j,n){
        cout << a[j];
        if(j!=n-1) cout << " ";
    }
    cout << endl;
}

void bubbleSort(vector<int> a,int n){
    int flag = 1,cnt = 0;
    while(flag){
        flag = 0;
        for(int i=n-1;i>=1;i--){
            if(a[i]<a[i-1]){
                swap(a[i],a[i-1]);
                cnt++;
                flag = 1;
            }
        }
    }
    out(a,n);
    cout << cnt << endl;
}

int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i,n) cin >> a[i];
    bubbleSort(a,n);
    return 0;
}
