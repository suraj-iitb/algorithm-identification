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

void selectionSort(vector<int> a,int n){
    int cnt = 0;
    rep(i,n){
        int minj = i;
        for(int j=i;j<n;j++){
            if(a[j]<a[minj]) minj = j;
        }
        swap(a[i],a[minj]);
        if(i!=minj) cnt++;
    }
    out(a,n);
    cout << cnt << endl;
}

int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i,n) cin >> a[i];
    selectionSort(a,n);
    return 0;
}
