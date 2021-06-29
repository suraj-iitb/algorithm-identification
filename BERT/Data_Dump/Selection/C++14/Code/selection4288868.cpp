#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    
    int counter = 0;
    for (int i = 0; i < n; i++) {
        int mini = i;
        for (int j = i; j < n; j++) {
            if (a[mini] > a[j])
                mini = j;
        }
        if (i != mini) {
            swap(a[i], a[mini]);
            counter++;
        }
    }
    for (int i = 0; i < n; i++) {
        cout << a[i];
        if (i < n - 1)
            cout << " ";
    }
    cout << '\n' << counter << '\n';

    return 0;
}
