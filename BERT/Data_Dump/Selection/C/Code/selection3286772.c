#include <stdio.h>

int main(){
  int i, j, min, tmp,len,count=0;
  int a[1000];
  scanf("%d",&len);
  for(i=0;i<len;i++){
    scanf("%d",&a[i]);
  }
  for(i=0; i<len; i++){
    min=i;
    for(j=i+1;j<len;j++){
      if(a[j]<a[min]){
        min=j;
      }
    }
    if(min!=i){
      tmp=a[i];
      a[i]=a[min];
      a[min]=tmp;
      count++;
    }

  }
  for (i = 0; i < len-1; i++) {
    printf("%d ", a[i]);
  }
  printf("%d",a[len-1]);
  printf("\n");
  printf("%d\n",count);
  return 0;
}
