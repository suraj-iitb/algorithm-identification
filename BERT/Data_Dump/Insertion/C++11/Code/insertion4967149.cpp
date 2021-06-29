#include<iostream>
using namespace std;
int main(){
    int n;
    cin >> n;
    int a[n];
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < n; i++){
        for(int j = 0; j < i; j++){
            if(a[j] > a[i]) swap(a[j], a[i]);
        }
        for(int j = 0; j < n; j++){
            cout << a[j];
            if(j < n-1) cout << ' ';
        }
        cout << '\n';
    }
    return 0;
}
