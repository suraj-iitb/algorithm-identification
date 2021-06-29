#include <iostream>
#include <string>
#include <vector>
using namespace std;
typedef long long ll;
const int INF = 1<<30; 
const int MOD = 1e9 + 7;
const int dy[] = {1, 0, -1, 0};
const int dx[] = {0, 1, 0, -1};
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
        for(int j = n - 1; j > 0; j--)
        {
            if(A[j - 1] > A[j])
            {
                swap(A[j], A[j - 1]);
                cnt++;
            }
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


