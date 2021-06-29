#include <iostream>
#include<vector>
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
        int minj=i;
        F(j,i,n){
            if(a[j]<a[minj]){
                minj=j;
            }
        }
        if(i!=minj){
            int t=a[i];
            a[i]=a[minj];
            a[minj]=t;
            ++cnt;
        }
    }
    F(i,0,n){
        cout << a[i];
        if(i!=n-1) cout << ' ';
    }
    cout << endl << cnt << endl;
    return 0;
}
