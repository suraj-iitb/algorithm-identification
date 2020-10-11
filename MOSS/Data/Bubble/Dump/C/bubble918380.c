#include <stdio.h>
main(){
  int len,a[100],tmp,count=0,i,j;

  scanf("%d",&len);
  for(i=0; i<len; i++)
    scanf("%d",&a[i]);

  for(i=0; i<len-1; i++){
    for(j=len-1; j>i; j--){
      if(a[j]<a[j-1]){
	tmp=a[j-1];
	a[j-1]=a[j];
	a[j]=tmp;
	count++;
      }
    }
  }

  for(i=0; i<len; i++){
    if(i>=0 && i<len-1) printf("%d ",a[i]);
    else printf("%d\n",a[i]);
  }

  printf("%d\n",count);
  return 0;
}
