#include<stdio.h>
int main(void){
  int i,j,n,len,mini,c,count=0;
  int A[100];
  scanf("%d",&len);
  for(i=0;i<len;i++){
    scanf("%d",&A[i]);
  }
  for(i=0;i<len;i++){
    mini=i;
    for(j=i;j<len;j++){
      if(A[j]<A[mini]){
	mini=j;
      }
    }
    if(i!=mini){
    c=A[i];
    A[i]=A[mini];
    A[mini]=c;
    count++;
    }
  }
  for(i=0;i<len;i++){
    if(i!=0){
      printf(" ");
    }
    printf("%d",A[i]);
  }
  printf("\n%d\n",count);

  return 0;
}
