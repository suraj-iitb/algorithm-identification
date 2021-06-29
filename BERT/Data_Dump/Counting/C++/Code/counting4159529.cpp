#include <iostream>
#include <cstdio>
#include <vector>
#include <cstdlib>
using namespace std;

#define MAX 2000000

int main()
{
    int n;
    cin >> n;

    int *A, *B;
    A = (int *) calloc(sizeof(int), n + 1);
    B = (int *) calloc(sizeof(int), n + 1);

    for(int i = 1; i <= n; i++) scanf("%d", &A[i]);

    int C[10001] = {0};
    for(int i = 1; i <= n; i++) C[A[i]]++;

    for(int i = 1; i < 10001; i++)
    {
        C[i] += C[i - 1];
    }

    for(int i = n; i >= 0; i--)
    {
        B[C[A[i]]] = A[i];
        C[A[i]]--;
    }

    for(int i = 1; i <= n; i++)
    {
        if(i - 1) cout << " ";
        cout << B[i];
    }

    cout << endl;

    return 0;
}
