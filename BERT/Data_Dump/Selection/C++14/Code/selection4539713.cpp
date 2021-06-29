#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i=0; i<(n); i++)
template <typename T>
vector<T> selectionsort(vector<T> &a){
    int count=0;
    for(int i=0; i<a.size(); i++){
        T minj = i;
        for(int j=i; j<a.size(); j++){
            if(a[minj] > a[j]){
                minj = j;
            }
        }
        if (minj != i){
            swap(a[i], a[minj]);
            count++;
        }
    }
    rep(i, a.size()){
        cout << a[i];
        if (i == a.size()-1) cout << endl;
        else cout << " ";
    }
    cout << count << endl;
    return a;
}
int main(){
    int n; cin >> n;
    vector<int> a(n);
    rep(i, n) cin >> a[i];
    selectionsort<int>(a);
    return 0;
}
