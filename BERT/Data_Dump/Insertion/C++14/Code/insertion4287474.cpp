#include <bits/stdc++.h>
using namespace std;
void disp(vector<int> &v) {
    for(int i = 0; i < v.size(); i++) {
        cout << v[i];
        if (i < v.size() - 1)
            cout << " ";
    }
    cout << "\n";
}
int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++)
        cin >> a[i];
    
    disp(a);
    for(int i = 1; i < n; i++) {
        int v = a[i];
        int j = i - 1;
        while (j >= 0 && a[j] > v)
        {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = v;
        disp(a);
    }

  
    return 0;
}
