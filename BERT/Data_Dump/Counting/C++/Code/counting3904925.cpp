#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int k = 0;
    int A [n+1], B [n+1];
    for(int i = 1; i <= n; i++) {
        cin >> A[i];
        if(A[i] > k) k = A[i];
    }
    int C [++k];
    for(int i = 0; i < k; i++) C[i] = 0;
    for(int i = 1; i <= n; i++) C[A[i]]++;
    for(int i = 1; i < k; i++) C[i] += C[i-1];
    for(int i = n; i > 0; i--) B[C[A[i]]--] = A[i];
    for(int i = 1; i < n; i++) cout<< B[i] << " "; cout<< B[n] << "\n";

    return 0;
}
