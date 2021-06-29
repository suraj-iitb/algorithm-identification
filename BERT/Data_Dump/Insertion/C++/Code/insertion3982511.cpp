#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i=0; i<(n); i++)
int main()
{
    int n;
    cin >> n;
    vector<int> a(n);

    rep(i, n){
        cin >> a[i];
    }

    int tmp;
    for(int i=0; i<n; i++){
        tmp = a[i];
        for(int j=i-1; j>=0; j--){
            if(tmp < a[j]){
                a[j+1] = a[j];
                a[j] = tmp;
            }
            else{
                break;
            }
        }

        rep(k, n){
            cout << a[k];
            if(k != n-1){
                cout << " ";
            }
        }
        cout << "\n";
    }

    return 0;
}
