#include <iostream> 
#define MAX 100000
using namespace std;

int main() 
{
    int n; cin >> n;
    int A[n+1], B[n+1], C[MAX+1];
    for (int i = 0; i < n; ++i) 
    {
        cin >> A[i];
    }
    for (int i = 0; i <= MAX; ++i) C[i] = 0;

    for (int i = 0; i < n; ++i) ++C[A[i]];

    // 累積和を計算する
    for (int i = 1; i <= MAX; ++i) C[i] += C[i-1];

    for (int i = n-1; i >= 0; --i) B[C[A[i]]--] = A[i];

    // index of B starts from 1
    for (int i = 1; i <= n; ++i) 
    {
        if (i != 1) cout << ' ';
        cout << B[i];
    }
    cout << endl;
}
