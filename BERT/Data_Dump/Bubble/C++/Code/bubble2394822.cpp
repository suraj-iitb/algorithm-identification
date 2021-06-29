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
    int i, j, n, flag = 1, swapTime = 0;;
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        scanf("%d", &num[i]);
    }
    for (i = 0; flag; i++) {
        flag = 0;
        for (j = n - 1; j > i; j--) {
            if (num[j] < num[j - 1]) {
                swap(num[j], num[j - 1]);
                swapTime++;
                flag = 1;
            }
        }
    }
    printNum(n);
    printf("%d\n", swapTime);
    return 0;
}
