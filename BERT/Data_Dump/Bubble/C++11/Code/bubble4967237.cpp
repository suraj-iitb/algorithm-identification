#include<iostream>
using namespace std;
int main(){
    int n, ans = 0;
    cin >> n;
    int a[n];
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < n; i++){
        for(int j = n-1; j > i; j--){
            if(a[j] < a[j-1]){
                swap(a[j], a[j-1]);
                ans++;
            }
        }
    }
    for(int i = 0; i < n; i++){
        cout << a[i];
        if(i < n-1) cout << ' ';
    }
    cout << '\n' << ans << '\n';
    return 0;
}
