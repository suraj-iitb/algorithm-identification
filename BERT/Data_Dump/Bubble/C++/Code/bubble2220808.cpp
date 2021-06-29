#include <stdio.h>

int bubble_sort(int *a, int n);
void swap(int *a, int *b);

int main(int argc, char const *argv[])
{
  int i,n, a[100],count;
  scanf("%d", &n);
  for(i=0;i<n;i++) {
    scanf("%d", a+i);
  }
  count=bubble_sort(a,n);
  for(i=0;i<n-1;i++) {
    printf("%d ", *(a+i));
  }
  printf("%d\n", *(a+i));
  printf("%d\n", count);
  return 0;
}

int bubble_sort(int *a, int n)
{
  int i, count=0, flag;
  flag = 1;
  while (flag) {
    flag = 0;
    for(i=n-1;i>0;i--) {
      if(a[i] < a[i-1]) {
        swap(a+i,a+i-1);
        count++;
        flag=1;
      }
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
