#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    
    bool flag = true;
    int count = 0;
    while (flag)
    {
        flag = false;
        for (int j = n - 1; j > 0; j--) {
            if (a[j] < a[j - 1]) {
                swap(a[j], a[j - 1]);
                flag = true;
                count++;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        cout << a[i];
        if (i < n - 1)
            cout << " ";
    }
    cout << '\n' << count << '\n';

    return 0;
}
