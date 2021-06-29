#include<cstdio>
#include<algorithm>

#define MAX_N 100

using namespace std;

int num[MAX_N];

void printNum(int n)
{
    int i;
    printf("%d", num[0]);
    for (i = 1; i < n; i++) {
        printf(" %d", num[i]);
    }
    printf("\n");
}

int main()
{
    int i, j, k, n;
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        scanf("%d", &num[i]);
    }
    printNum(n);
    for (i = 1; i < n; i++) {
        k = num[i];
        j = i - 1;
        while ((j >= 0) && (num[j] > k)) {
            num[j + 1] = num[j];
            j--;
        }
        num[j + 1] = k;
        printNum(n);
    }

    return 0;
}
