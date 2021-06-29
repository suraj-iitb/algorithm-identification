#include <bits/stdc++.h>
using namespace std;
#define F(i,s,e) for(int i=s;i<e;++i)

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    F(i,0,n) cin >> a[i];

    int cnt=0;
    F(i,0,n){
        for(int j=n-1;j>i;--j){
            if(a[j]<a[j-1]){
                int t=a[j];
                a[j]=a[j-1];
                a[j-1]=t;
                ++cnt;
            }
        }
    }

    F(i,0,n){
        cout << a[i];
        if(i!=n-1) cout << ' ';
    }
    cout << endl << cnt << endl;
    return 0;
}
