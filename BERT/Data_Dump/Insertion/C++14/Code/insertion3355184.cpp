#include <iostream>
#include <string>
#include <vector>
using namespace std;
typedef long long ll;
const int INF = 1<<30; 
const int MOD = 1e9 + 7;
void print(int A[], int n)
{
    for(int i = 0; i < n; i++)
    {
        if(i) cout << " ";
        cout << A[i];
    }
    cout << endl;
}
int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n; cin >> n;
    int A[n + 1];
    for(int i = 0; i < n; i++) cin >> A[i];
    print(A, n);
    for(int i = 1; i < n; i++)
    {
        int a = i;
        int b = i - 1;
        while(A[a] < A[b] && b >= 0)
        {
            swap(A[a], A[b]);
            a--;
            b--;
        }
        print(A, n);
    }
    return 0;
}

