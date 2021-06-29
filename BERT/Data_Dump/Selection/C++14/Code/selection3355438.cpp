#include <iostream>
#include <string>
#include <vector>
using namespace std;
typedef long long ll;
const int INF = 1<<30; 
const int MOD = 1e9 + 7;
int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n; cin >> n;
    int A[n + 1];
    for(int i = 0; i < n; i++) cin >> A[i];
    int cnt = 0;
    for(int i = 0; i < n; i++)
    {
        int minA = A[i], idx = -1;
        for(int j = i + 1; j < n; j++)
        {
            if(A[j] < minA)
            {
                minA = A[j];
                idx = j;
            }
        }
        if(idx != -1)
        {
            swap(A[i], A[idx]);
            cnt++;
        }
    } 
    for(int i = 0; i < n; i++)
    {
        if(i) cout << " ";
        cout << A[i];
    }
    cout << endl;
    cout << cnt << endl;
    return 0;
}

