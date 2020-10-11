#include<stdio.h>
#define N 100
int main(){
  int ary[N];
  int i,j,n,minj,tmp,count=0,flag=0;
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&ary[i]);
  }
  for(i=0;i<n-1;i++){
    minj=i;
    for(j=i+1;j<n;j++){
      if(ary[j]<ary[minj]){
	minj=j;
	flag=1;
      }
    }
    tmp=ary[i];
    ary[i]=ary[minj];
    ary[minj]=tmp;
    if(flag==1){
      count++;
    }
    flag=0;
  }
  for(i=0;i<n;i++){
    if(i>0)printf(" ");
    printf("%d",ary[i]);
  }
  printf("\n%d\n",count);
}

