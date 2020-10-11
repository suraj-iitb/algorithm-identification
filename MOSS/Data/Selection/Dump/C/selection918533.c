#include <stdio.h>
main(){
  int a[100],i,j,tmp,len,min,count=0;

  scanf("%d",&len);
  for(i=0; i<len; i++)
    scanf("%d",&a[i]);

  for(i=0; i<len; i++){
    min=i;
    for(j=i; j<len; j++){
      if(a[j]<a[min])
	min=j;
    }
    tmp=a[i];
    a[i]=a[min];
    a[min]=tmp;
    if(min!=i) count++;
  }
  for(i=0; i<len-1; i++)
    printf("%d ",a[i]);
  printf("%d\n%d\n",a[len-1],count);
  return 0;
}
