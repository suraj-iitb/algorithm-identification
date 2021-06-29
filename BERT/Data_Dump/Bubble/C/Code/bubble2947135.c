#include<stdio.h>
#include<stdlib.h>
#define N 100
int main(){
  int A[N],a,i,j,flag=1,cnt=0,v;
  scanf("%d",&a);
  if(a<1 || a>100)exit(0);
  for(i=0;i<a;i++){
    scanf("%d",&A[i]);
    if(A[i]<0 || A[i]>100)exit(1);
  }
  while(flag==1){
    flag=0;
    for(j=a-1;j>0;j--){
      if(A[j]<A[j-1]){
	v=A[j-1];
	A[j-1]=A[j];
	A[j]=v;
	flag=1;
	cnt++;
      }
    }
  }
  for(i=0;i<a;i++){
    printf("%d",A[i]);
  if(i==a-1)printf("\n");
  else printf(" ");
  }
  printf("%d\n",cnt);

  return 0;
}

