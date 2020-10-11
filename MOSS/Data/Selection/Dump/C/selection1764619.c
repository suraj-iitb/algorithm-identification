#include <stdio.h>
#define N 100

int main()
{

int n, A[N], i, j, k, l, num, count=0;

scanf("%d", &n);
for(i = 0; i < n; i++) scanf("%d", &A[i]);

for(i = 0; i < n-1; i++){
k = i;
for(j = i; j < n; j++){
if(A[j] < A[k]) k = j;
}
num = A[i];
A[i] = A[k];
A[k] = num;
if(i != k) count++;
}

for(l = 0; l < n; l++){
if(l == n-1) printf("%d", A[l]);
else printf("%d ", A[l]);
}
printf("\n%d\n", count);

return 0;
}
