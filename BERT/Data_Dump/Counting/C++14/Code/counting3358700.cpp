#include <iostream>
#include <string>
#include <vector>
using namespace std;
typedef long long ll;
const int INF = 1<<30; 
const int MOD = 1e9 + 7;
const int MAX_N = 10010;
int res[2001000];
void CountingSort(int A[], int n)
{
    int num[MAX_N] = {};
    for(int i = 0; i < n; i++) num[A[i]]++;
    int pos = 0;
    for(int i = 0; i < MAX_N; i++)
    {
        while(num[i] != 0)
        {
            res[pos] = i;
            pos++;
            num[i]--;
        }
    }
}
int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n; cin >> n;
    int A[n + 1];
    for(int i = 0; i < n; i++) cin >> A[i];
    CountingSort(A, n);
    for(int i = 0; i < n; i++)
    {
        if(i) cout << " ";
        cout << res[i];
    }
    cout << endl;
    return 0;
}


