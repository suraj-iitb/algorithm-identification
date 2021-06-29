#include<iostream>
using namespace std;
int main(){
    int n, ans = 0;
    cin >> n;
    int a[n];
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < n; i++){
        int mini = i;
        for(int j = i; j < n; j++){
            if(a[mini] > a[j]) mini = j;
        }
        if(a[mini] < a[i]){
            swap(a[mini], a[i]);
            ans++;
        }
    }
    for(int i = 0; i < n; i++){
        cout << a[i];
        if(i < n-1) cout << ' ';
    }
    cout << '\n' << ans << '\n';
    return 0;
}
