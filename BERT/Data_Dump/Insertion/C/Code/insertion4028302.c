#include<stdio.h>

int main(){
  int i=0,l,j,s;
  int A[100];
  int key;
  scanf("%d",&l);
  for(i=0;i<l;i++)scanf("%d",&A[i]);
  for(s=0;s<l;s++)if(s==l-1)printf("%d",A[s]);else printf("%d ",A[s]);
  printf("\n");
  
  for(i=1;i<l;i++){
    key=A[i];
    j=i-1;
    while(j>=0&&A[j]>key){//keyがあるべき位置に来るまでループする
      A[j+1]=A[j];
      j--;
      A[j+1]=key;
    }
    for(s=0;s<l;s++)if(s==l-1)printf("%d",A[s]);else printf("%d ",A[s]);
    printf("\n");
  }
  return 0;
}

