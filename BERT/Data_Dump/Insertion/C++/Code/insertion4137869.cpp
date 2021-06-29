#include <iostream>
#include<algorithm>
#include<iomanip>
#include<vector>
using namespace std;
#define c(v) cout << fixed << setprecision(10) << v << endl;
#define rep(i,n) for(int i = 0; i < n; i++)
int x[1100]; vector<double> v;
int main()
{
    int n; 
    cin >> n;
    rep(i, n) {
        cin >> x[i];
    }
    rep(i, n - 1) {
        cout << x[i] << " ";
    }
    cout << x[ n - 1] << endl;
    for (int i = 1; i < n; i++) {
        int v = x[i]; int j = i - 1;
        while (j >= 0 && x[j] > v) {
            x[j + 1] = x[j];
            j--;
            x[j + 1] = v;
        }
        rep(i, n - 1)
            cout << x[i] << " ";
        cout <<  x[n - 1] << endl;
    } 
}
