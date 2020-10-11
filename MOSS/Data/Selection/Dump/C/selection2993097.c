#include <stdio.h>

int main(void) {
  int a[101],n,min,minpoint,change,i,j,count = 0;
  scanf("%d",&n);
  for(i = 0; i < n; i++)scanf("%d",&a[i]);

  for(i = 0; i < n; i++){
    minpoint = i;
    min = 999;
    for(j = i; j < n; j++){
      if(min > a[j]){
        min = a[j];
        minpoint = j;
      }
    }
    change = a[i];
    a[i] = a[minpoint];
    a[minpoint] = change;
    if(minpoint != i)count++;
  }
  for(i = 0; i < n; i++){
    if(i != 0)printf(" ");
    printf("%d",a[i]);
  }
  printf("\n%d\n",count);
}
