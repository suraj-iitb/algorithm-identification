#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

static int cnt;

static void
print_array(int A[], size_t len)
{
        for (int i = 0; i < len; i++) {
                if (i)
                        printf(" ");
                printf("%d", A[i]);
        }
        printf("\n");
}

static void
merge(int A[], int left, int mid, int right)
{
        int n1 = mid - left;
        int n2 = right - mid;
        int *L = malloc(sizeof(int) * (n1 + 1));
        int *R = malloc(sizeof(int) * (n2 + 1));

        memcpy(L, &A[left], sizeof(int) * n1);
        memcpy(R, &A[mid], sizeof(int) * n2);

        L[n1] = INT_MAX;
        R[n2] = INT_MAX;

        for (int i = 0, j = 0, k = left; k < right; k++) {
                if (L[i] <= R[j]) {
                        A[k] = L[i];
                        i++;
                } else {
                        A[k] = R[j];
                        j++;
                }
                cnt++;
        }

        free(L);
        free(R);
}

static void
merge_sort(int A[], int left, int right)
{
        if ((left + 1 ) < right) {
                int mid = (left + right) / 2;
                merge_sort(A, left, mid);
                merge_sort(A, mid, right);
                merge(A, left, mid, right);
        }
}

int
main(void)
{
        int n;

        scanf("%d", &n);
        int *S = malloc(sizeof(int) * n);
        for (int i = 0; i < n; i++)
                scanf("%d", &S[i]);

        merge_sort(S, 0, n);

        print_array(S, n);
        printf("%d\n", cnt);

        free(S);

        return 0;
}

