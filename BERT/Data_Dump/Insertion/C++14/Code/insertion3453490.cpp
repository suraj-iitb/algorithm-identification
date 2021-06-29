#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
string out(vector<int> ve, int size) {
    string s;
    for (int i = 0; i < size-1; ++i)
    {
        s += to_string(ve[i]) + " ";
    }
    s += to_string(ve[size-1]);
    return s;
}
 
int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }
    cout << out(a, n) << endl;
 
    for (int i = 1; i < n; ++i)
    {
        int v = a[i];
        int j = i-1;
        while (j >= 0 && a[j] > v)
        {
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = v;
        cout << out(a, n) << endl;
    }
 
    return 0;
}
