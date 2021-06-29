#include <stdio.h>
#define N 500000
int A[N],count=0;
void Merge(int a[N], int left, int right);
int main(void);
void Merge(int a[N], int left, int right)
{
  int mid, i, j, k;
    if (left >= right)
        return;
    mid = (left + right) / 2;
    Merge(a, left, mid);
    Merge(a, mid + 1, right);
    for (i = left; i <= mid; i++)
      A[i] = a[i];
    for (i = mid + 1, j = right; i <= right; i++, j--)
        A[i] = a[j];
    i = left;
    j = right;
    for (k = left; k <= right; k++)
      if (A[i] <= A[j]){
        a[k] = A[i++];
    count++;
      }
    else{
      a[k] = A[j--];
      count++;
    }
}
int main(void)
{
  int i,total;
    int A[N];
    scanf("%d",&total);
    for(i=0;i<total;++i)
      scanf("%d",&A[i]);
      Merge(A, 0, total - 1);
      for (i = 0; i < total; i++){
        if(i){
          printf(" ");
        }
        printf("%d", A[i]);
      }
      printf("\n");
      printf("%d\n",count);
      return 0;
}

