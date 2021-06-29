#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i=0; i<(n); i++)
template <typename T>
vector<T> bubblesort(vector<T> &a, int n){
    bool flag = true;
    int i=0;
    int count = 0;
    while(flag){
        flag = false;
        for(int j=n-1; j>i; --j){
            if(a[j] < a[j-1]){
                swap(a[j], a[j-1]);
                count++;
                flag = true;
            }
        }
    }
    for(int i=0; i<n; i++){
        cout << a[i];
        if (i == n-1) cout << endl;
        else cout << " ";
    }
    cout << count << endl;
    return a;
}
int main(){
    int n; cin >> n;
    vector<int> b(n);
    rep(i, n) cin >> b[i];
    bubblesort<int>(b, n);
    
}
