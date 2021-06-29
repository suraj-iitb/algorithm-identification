#include <stdio.h>
int main(){
  int A[100];
  int i,min,j,len,count=0,sw,t;
  scanf("%d",&len);
  for(i=0;i<len;i++){
    scanf("%d",&A[i]);
  } 
  for(i=0;i<len;i++){
    min=i;
    for(j=i;j<len;j++){
      if(A[j]<A[min]){
	min=j;
      }
    }
    if(min>i){
      sw=A[i];
      A[i]=A[min];
      A[min]=sw;
      count++;
    }
  }
  
  
  for(i=0;i<len;i++){
    printf("%d",A[i]);
    if(i==len-1) printf("\n");
    else printf(" ");
  }
  printf("%d\n",count);
  return 0;
}
