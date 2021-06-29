#include<iostream>
#include<cmath>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
    int n,cnt=0;
    cin >> n;
    vector<int> a(n);
    for(int i=0;i<n;i++)cin >> a[i];

    bool ok = true;
    while(ok){
        ok = false;
        for(int j=n-1;j>0;j--){
            if(a[j] < a[j-1]){
                swap(a[j], a[j-1]);
                cnt++;
                ok = true;
            }
        }
    }

    for(int i=0;i<n;i++){
        cout << a[i];
        if(i != n-1)cout << " ";
        else cout << endl;
    }
    cout << cnt << endl;

    return 0;
}
