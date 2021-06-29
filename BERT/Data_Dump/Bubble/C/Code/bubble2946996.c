#include<stdio.h>
#define N 100
int main(){
  int ary[N];
  int i,j,n,tmp,count=0;
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&ary[i]);
  }
  for(i=0;i<n-1;i++){
    for(j=n-1;j>i;j--){
      if(ary[j]<ary[j-1]){
	tmp=ary[j];
	ary[j]=ary[j-1];
	ary[j-1]=tmp;
	count++;
      }
    }
  }
  for(i=0;i<n;i++){
    if(i>0)printf(" ");
    printf("%d",ary[i]);
  }
  printf("\n%d\n",count);
  return 0;
}

