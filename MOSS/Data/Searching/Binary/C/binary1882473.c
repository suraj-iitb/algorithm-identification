#include <stdio.h>
#include <stdlib.h>
 
int binsearch(int S[], int n, int key)
{
    int left = 0;
    int right = n;
    int mid;
     
    while (left < right) {
        mid = (left + right)/2;
        if (S[mid] == key) 
            return 1;
        else if (S[mid] < key)
            left = mid+1;
        else
            right = mid;
    }
    return 0;
}
 
int main()
{
    int n, q;
    int *S, T;
    int i, j = 0;
    int *A;
     
    scanf("%d", &n);
    S = (int*)malloc(sizeof(int) * n);
    for (i = 0; i < n; i++) {
        scanf("%d", &S[i]);
    }
     
    scanf("%d", &q);
    for (i = 0; i < q; i++) {
        scanf("%d", &T);
        if (binsearch(S, n, T)) {
            j++;
        }
    }
     
    printf("%d\n", j);
     
    return 0;
}
