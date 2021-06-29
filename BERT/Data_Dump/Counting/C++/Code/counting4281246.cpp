#include <iostream>
#define N 2000000
using namespace std;
int A[N], B[N];
void countSort(int A[], int B[], int n){
    int i;
    int C[10000];
    for (i = 0; i < 10000; i++)
        C[i] = 0;
    for (i = 0; i < n; i++)
        C[A[i]]++;
    for (i = 1; i < 10000; i++)
        C[i] += C[i-1];
    for (i = n-1; i >= 0; i--){
        B[C[A[i]]-1] = A[i];
        C[A[i]]--;
    }
}
int main()
{
    int i, n;

    cin >> n;
    for (i = 0; i < n; i++)
        cin >> A[i];
    countSort(A, B, n);
    for (i = 0; i < n; i++){
        if (i) cout << ' ';
        cout << B[i];
    }
    cout << endl;
    return 0;
}

