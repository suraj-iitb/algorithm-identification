#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;

int bubbleSort(vector<int> &a, int n){
    int ans = 0;
    bool flag = 1;
    int i = 0;
    while(flag){
        flag = 0;
        for(int j = n-1; j > i; j--){
            if (a[j] < a[j-1]){
                swap(a[j], a[j-1]);
                flag = 1;
                ans++;
            }
        }
        i++;
    }
    return ans;
}

int main() {
    int n;
    cin>>n;
    vector<int> a(n);
    rep(i,n) cin>>a[i];
    int ans = bubbleSort(a, n);
    rep(i, n-1) cout << a[i] <<" ";
    cout << a[n-1] <<endl;
    cout << ans <<endl;
  return 0;
}
