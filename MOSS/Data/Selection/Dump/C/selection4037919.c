#include<stdio.h>
#define N 100
int main(){
  int a,i,j,k,A[N],min,head,flag=0;
  scanf("%d",&a);
  for(i=0;i<a;i++){
    scanf("%d",&A[i]);
  }
  for(i=0;i<a-1;i++){
    min = A[i];
    k = i;
    for(j=i+1;j<a;j++){
      if(A[j]<min){
	min=A[j];
	k=j;
      }
    }
    if(i!=k){
    head=A[i];
    A[i]=A[k];
    A[k]=head;
    	flag++;
    }
  }
  for(i=0;i<a;++i){
    if(i>0)printf(" ");
    printf("%d",A[i]);
  }
  printf("\n");
  printf("%d\n",flag);
  return 0;
}
