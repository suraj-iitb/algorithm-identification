#include<iostream>
#include<vector>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    int cnt=0;
    for(int i=0; i<n; i++) cin >> a[i];
    for(int i=0; i<n; i++){
        for(int j=n-1; j>i; j--){
            if(a[j]<a[j-1]){
                swap(a[j],a[j-1]);
                cnt++;
            }
        }
    }
    for(int i=0; i<n; i++){
        if(i!=n-1) cout << a[i] << " ";
        else cout << a[i] << endl;
    }
    cout << cnt << endl;
    return 0;
}
