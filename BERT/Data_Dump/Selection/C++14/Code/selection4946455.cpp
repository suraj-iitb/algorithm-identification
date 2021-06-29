#include <iostream>
using namespace std;
int main (){
    int n, minj, s, p, ans;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i ++ ){
        cin >> a[i];
    }
    for (int i = 0; i < (n - 1); i ++ ){
        minj = a[i];
        int flag = 0;
        for (int k = i; k < n; k ++){
            if (minj > a[k]){
                minj = a[k];
                s = k;
                flag ++;
            }
        }
        if (flag != 0){
            a[s] = a[i];
            a[i] = minj;
            ans ++;
        }
    }
    for (int k = 0; k < n; k ++){
        if (k == 0)cout << a[k];
        else cout << " " << a[k];
    }
    cout << endl << ans << endl;
}
