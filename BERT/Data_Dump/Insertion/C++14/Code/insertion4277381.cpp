#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
const long long INF = numeric_limits<long long>::max();
typedef long long ll;

void trace(vector<int> a, int n)
{
    for(int i=0; i<n; i++){
        if (i == n-1) cout << a[i] << endl;
        else cout << a[i] << " ";
    }
}
void insertation_sort(vector<int> &a, int n)
{
    for(int i=1; i<n; i++){
        int v = a[i];
        int j = i - 1;
        while(1){
            if(j < 0 || v > a[j]) break;
            a[j+1] = a[j]; 
            j--;
        }
        a[j+1] = v;
        trace(a, n);
    }
}
int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i,n) cin >> a[i];
    trace(a, n);
    insertation_sort(a, n);
    return 0;
}
