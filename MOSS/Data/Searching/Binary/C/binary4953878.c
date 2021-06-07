#include<stdio.h>

int BinarySearch(int A[], int n, int key) {
    int left = 0 , right = n, mid;

    while (left < right) {
        mid = (left + right) / 2;
        if (key == A[mid])
            return 1;

        if(key > A[mid])
            left = mid + 1;
        if (key < A[mid])
            right = mid;
    }
    return 0;

}
int main() {
    int n, q, k;
    int sum = 0;
    int A[100010];
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &A[i]);
    scanf("%d", &q);
    for (int i = 0; i < q; i++) {
        scanf("%d", &k);
        if (BinarySearch(A, n, k))
            sum++;
    }
    printf("%d\n", sum);
    return 0;
}
