#include <cstdio>
#include <cstdlib>
using namespace std;
#define MAX 2000005
int A[MAX], ans[MAX], cnt[10005];

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &A[i]);
        ++cnt[A[i]];
    }
    for (int i = 1; i <= 10000; ++i)
        cnt[i] += cnt[i - 1];
    for (int i = n - 1; i >= 0; --i)
        ans[cnt[A[i]]--] = A[i];
    for (int i = 1; i <= n; ++i) {
        if (i != 1) printf(" ");
        printf("%d", ans[i]);
    }
    printf("\n");
    return 0;
}

