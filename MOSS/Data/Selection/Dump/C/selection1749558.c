#include<stdio.h>

int main(){
  int i,j,k,n,a[100],min,count=0;

  scanf("%d",&n);
  for(i = 0;i < n;i++){
    scanf("%d",&a[i]);
  }

  for(i = 0;i < n;i++){
    min = i;
    for(j = i;j < n;j++){
      if(a[j] < a[min]){
	min  = j;
      }
    }
    if(a[i] != a[min]){
      k = a[i];
      a[i] = a[min];
      a[min] = k;
      count++;
    }
  }

  for(i = 0;;i++){
    printf("%d",a[i]);
    if(i >= n - 1)break;
    printf(" ");
  }
  printf("\n%d\n",count);

  return 0;
}
