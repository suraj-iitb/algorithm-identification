#include <iostream>
#include <string>
#include <vector>
using namespace std;
typedef long long ll;
const int INF = 1<<30; 
const int MOD = 1e9 + 7;
int Mergesort(vector<int> &v, int left, int right)
{
    if(right - left <= 1) return 0;
    int res = 0;
    int mid = (left + right) / 2;
    res += Mergesort(v, left, mid);
    res += Mergesort(v, mid, right);

    vector<int> buf;
    for(int i = left; i < mid; i++) buf.push_back(v[i]);
    for(int i = right - 1; i >= mid; i--) buf.push_back(v[i]);

    int pos1 = 0, pos2 = buf.size() - 1;
    for(int i = left; i < right; i++)
    {
        res++;
        if(buf[pos1] <= buf[pos2])
        {
            v[i] = buf[pos1];
            pos1++;
        }
        else
        {
            v[i] = buf[pos2];
            pos2--;
        }
    }
    return res;
} 
int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n; cin >> n;
    vector<int> v(n);
    for(int i = 0; i < n; i++) cin >> v[i];
    int ans = Mergesort(v, 0, n);
    for(int i = 0; i < n; i++)
    {
        if(i) cout << " ";
        cout << v[i];
    }
    cout << endl;
    cout << ans << endl;
    return 0;
}

