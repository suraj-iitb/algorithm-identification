#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, a, b) for (int i = a; i < b; i++)
//'A' = 65, 'Z' = 90, 'a' = 97, 'z' = 122

int main()
{
    int n;
    cin >> n;
    int a[n];
    rep(i, 0, n) cin >> a[i];
    rep(i, 0, n) {
        int tmp = a[i];
        int j = i - 1;
        while(j >= 0 && a[j] > tmp) {
            a[j + 1] = a[j];
            j --;
        }
        a[j + 1] = tmp;
        rep(i, 0, n) {
            if (i == n - 1) {
                cout << a[i] << endl;
            } else {
                cout << a[i] << " ";
            }
        }
    }
    return 0;
}

