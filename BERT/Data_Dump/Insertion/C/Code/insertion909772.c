#include <stdio.h>

int main(void){
  int i,j,a[105],key,len,k;
  scanf("%d",&len);
  for(i=0;i<len;i++){
    scanf("%d",&a[i]);
  }
  for(i=1;i<=len;i++){
    for(k=0;k<len;k++){
      printf("%d",a[k]);
      if(k!=len-1){
	printf(" ");
      }
    }
    printf("\n");
    key=a[i];
    j=i-1;
    while(j>=0 && a[j]>key){
      a[j+1]=a[j];
      j--;
      a[j+1]=key;
    }
  }
  
  return 0;
}
