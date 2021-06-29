#include <stdio.h>
typedef long long llong;
const int MAX = 2000002;
int AA[MAX];
int BB[MAX];

const int MAX_2 = 100001;
int C[MAX_2];
void C_sort(int A[],int B[],const int& k, const int& n)
{
    for (int i = 0; i <= k; i++)
        C[i] = 0;
    for (int i = 1; i <= n; i++)
        C[A[i]]++;
    for (int i = 1; i <= k; i++)
        C[i] = C[i] + C[i - 1];
    for (int i = n; i >= 0; i--)
    {
        B[C[A[i]]] = A[i];
        C[A[i]]--;
    }
}

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", &AA[i]);

    C_sort(AA, BB, 100000, n);
    printf("%d", BB[1]);
    for (int i = 2; i <= n; i++)
        printf(" %d", BB[i]);
    printf("\n");
    return 0;
}
