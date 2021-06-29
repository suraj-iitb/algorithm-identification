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
    int count = 0;
    for(int i=0; i<n-1; ++i){
        for(int j=n-1; j>i; --j){
            if(a[j] < a[j-1]){
                tmp = a[j-1];
                a[j-1] = a[j];
                a[j] = tmp;
                count++;
            }
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
