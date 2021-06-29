/*選択ソート*/

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

    int count = 0;
    rep(i, n){
        int minv = i;
        for(int j=i; j<n; ++j){
            if(a[minv] > a[j]){
                minv = j;
            }
        }
        if(minv != i){
            count++;
            int tmp = a[minv];
            a[minv] = a[i];
            a[i] = tmp;
        }
    }

    rep(k, n){
        cout << a[k];
        if(k != n-1){
            cout << " ";
        }
    }
    cout << "\n" << count << endl;

    return 0;
}
