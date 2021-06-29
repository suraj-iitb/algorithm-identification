#include <stdio.h>
#include <math.h>

int count,i;

void selectionSort(int x[], const int m)
{
  int minj,j,tmp;
  
  for(i=0;i<m;i++) {
    minj = i;
    for(j=i;j<m;j++) {
      if(x[j] < x[minj]) {
	    minj = j;
      }
    }
    if(minj != i) {
        tmp = x[i];
        x[i] = x[minj];
        x[minj] = tmp;
        count++;
    }
  }
}

int main(void)
{
  int a[100] = {0};
  int n;

  scanf("%d",&n);
  for(i=0;i<n;i++) {
    scanf("%d",&a[i]);
  }

  selectionSort(a,n);

  for(i=0;i<n;i++) {
    printf("%d",a[i]);
    if(i < n-1) {
      putchar(' ');
    }
    else {
        printf("\n");
    }
  }
  printf("%d\n",count);

  return(0);
}
