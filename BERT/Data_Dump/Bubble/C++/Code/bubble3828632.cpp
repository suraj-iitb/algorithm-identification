#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0;i < n;i++) cin >> a[i];

    bool f = true;
    int cnt = 0;
    while(f)
    {
        f = false;
        for(int i = n - 1;i > 0;i--){
            if(a[i - 1] > a[i]){
                cnt++;
                int t = a[i];
                a[i] = a[i - 1];
                a[i - 1] = t;
                f = true; 
            }
        }
    }

    for(int i = 0;i < n - 1;i++){
        cout << a[i] << " ";
    }
    cout << a[n - 1] << endl;
    cout << cnt << endl;
    return 0;
}
