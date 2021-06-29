#include <vector>
#include <iostream>

int main()  {
    using namespace std;

    int n;
    cin >> n;

    vector<int> a;

    for (int i=0; i < n; i++) {
        int x;
        cin >> x;
        a.push_back(x);
    }
    
    cout << a[0];  
    for (int i=1; i<n; i++) {
        cout << ' ' << a[i];    
    }
    cout << endl;

    for (int i=1; i<n; i++) {
        int v = a[i];
        int j = i-1;
        while (j >= 0 && a[j] > v)
        {
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = v;

        cout << a[0];  
        for (int i=1; i<n; i++) {
            cout << ' ' << a[i];    
        }
        cout << endl;
    }
}
