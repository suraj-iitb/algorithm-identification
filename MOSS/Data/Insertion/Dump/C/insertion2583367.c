#include<stdio.h>

int main ()
{
  int a[100],n,num,i,j,temp;
  scanf("%d",&n);
  for (i = 0; i < n; i++)
    scanf("%d", &a[i]); 
    for (j = 0; j < n-1; j++)
    printf("%d ",a[j]);
    printf("%d\n",a[n-1]);
  for (i = 1; i < n; i++) {
    num = i;
    for (j = 0; j < i; j++) {
      if (a[i] < a[j]) {
        num = j;
        break;
      }
    }
    temp = a[i];
    for(j = i; j > num; j--) {
      a[j]=a[j-1];
    }
    a[num] = temp;
    for (j = 0; j < n-1; j++)
    printf("%d ",a[j]);
    printf("%d\n",a[n-1]);
    }
  return 0;
}
