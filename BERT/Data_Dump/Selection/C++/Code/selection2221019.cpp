#include <stdio.h>

int selectionSort(int *a, int n);
void swap(int *a, int *b);

int main(int argc, char const *argv[])
{
  int a[100],n,i,count;
  scanf("%d", &n);
  for(i=0;i<n;i++) {
    scanf("%d", a+i);
  }
  count = selectionSort(a,n);
  for(i=0;i<n-1;i++)
    printf("%d ", a[i]);
  printf("%d\n", a[n-1]);
  printf("%d\n", count);
  return 0;
}

int selectionSort(int *a, int n)
{
  int i,j,count=0, minj;
  for(i=0;i<n;i++) {
    minj = i;
    for(j=i;j<n;j++) {
      if(a[j]<a[minj])
        minj = j;
    }
    if(minj != i) {
      swap(a+i,a+minj);
      count += 1;
    }
  }
  return count;
}

void swap(int *a, int *b)
{
  int temp;
  temp = *a;
  *a = *b;
  *b = temp;
}
