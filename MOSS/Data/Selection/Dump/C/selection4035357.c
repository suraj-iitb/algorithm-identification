#include <stdio.h>
#include <stdlib.h>

int main(){

  int n,i,j,tmp,cnt=0,min;
  int *a;
  
  scanf("%d",&n);

  a = malloc(sizeof(int)*n);

  for(i=0;i<n;i++)scanf("%d",&a[i]);

  for(i=0;i<n;i++){
    min = i;
    for(j=i;j<n;j++)if(a[j] < a[min])min = j;

    if(a[i]!=a[min]){
      tmp = a[i];
      a[i] = a[min];
      a[min] = tmp;
      cnt++;
    }
  }

  for(i=0;i<n-1;i++)printf("%d ",a[i]);
  printf("%d\n",a[i]);
  printf("%d\n",cnt);
 
  free(a);
  return 0;
}

