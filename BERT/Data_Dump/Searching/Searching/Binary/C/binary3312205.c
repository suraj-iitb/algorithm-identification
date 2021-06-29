#include  <stdio.h>
#define n_MAX 100000 + 1
//#define q_MAX 50000 + 1
int binarySearch(int *A, int key, int n) {
    int left = 0, right = n;
    while (left < right) {
        int mid = (left + right) / 2;
        if(A[mid] == key) {
            return mid;
        } else if (key < A[mid]) {
            right = mid;
        } else {
            left = mid + 1;
        }
    } 
    return -1;
}
int main()
{
    int i,key,n,q,S[n_MAX],sum = 0;
    scanf("%d",&n);
    for (i = 0; i < n; i++) scanf("%d",&S[i]);
    scanf("%d",&q);
    for (i = 0; i < q; i++) {
        scanf("%d",&key);
        if(binarySearch(S,key,n) != -1) sum++;
    } 
    printf("%d\n",sum);
    return 0;
}
