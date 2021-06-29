#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
const long long INF = numeric_limits<long long>::max();
typedef long long ll;

int ans = 0;

void trace(vector<int> a, int n)
{
    for(int i=0; i<n; i++){
        if (i == a.size()-1) cout << a[i] << endl;
        else cout << a[i] << " ";
    }
}

void BubbleSort(vector<int> &a, int n)
{
    bool flag = true;
    while(flag){
        flag = false;
        for(int i=n-1; i>0; i--){
            if (a[i] < a[i-1]){
                flag = true;
                swap(a[i], a[i-1]);
                ans++;
            }
        }
    }
}

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i,n) cin >> a[i];
    BubbleSort(a, n);
    trace(a, n);
    cout << ans << endl;;
    return 0;
}
