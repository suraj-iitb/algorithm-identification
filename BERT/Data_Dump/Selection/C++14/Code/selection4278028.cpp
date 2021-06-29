#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
const long long INF = numeric_limits<long long>::max();
typedef long long ll;

void trace(vector<int> a, int n)
{
    for(int i=0; i<n; i++){
        if (i == a.size()-1) cout << a[i] << endl;
        else cout << a[i] << " ";
    }
}

int SelectionSort(vector<int> &a, int n)
{
    int swap_cnt = 0;
    for(int i=0; i<n; i++){
        int min_j = i;
        for(int j = min_j; j<n; j++){
            if (a[min_j] > a[j]) min_j = j;
        }
        if (i != min_j){
            swap_cnt++;
            swap(a[i], a[min_j]);
        }
    }
    return swap_cnt;
}

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i,n) cin >> a[i];

    int ans = SelectionSort(a, n);
    trace(a, n);
    cout << ans << endl;

    return 0;
}
