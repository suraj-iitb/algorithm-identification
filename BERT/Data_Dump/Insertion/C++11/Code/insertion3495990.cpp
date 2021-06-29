#include <bits/stdc++.h>

#define REP(i, n) for(int i = 0; i < n; i++)
using namespace std;

int main()
{   
    int n;
    cin >> n;

    vector<int> ar(n);
    REP(i, n)   cin >> ar[i];
    
    REP(k, n-1) cout << ar[k] << " ";
    cout << ar[n-1] << endl;
    
    for (int i = 1; i < n; i++) {
        int j = i - 1;
        int v = ar[i];
        
        while (j >= 0 && v < ar[j]) {
            ar[j+1] = ar[j];
            j--;
        }

        ar[j+1] = v;

        REP(k, n-1) cout << ar[k] << " ";
        cout << ar[n-1] << endl;
    }
    
}
