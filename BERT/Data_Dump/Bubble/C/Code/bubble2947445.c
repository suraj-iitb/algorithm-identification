#include<stdio.h>
int main(){
  int i,j,N,count,ch,flag;
  int a[100];
  count=0;
  
  scanf("%d",&N);
  
  for(i=0;i<N;i++){
    scanf("%d",&a[i]);
  }
  flag=1;
  while(flag){
    flag=0;
    for(j=N-1;j>=1;j--){
      if(a[j]<a[j-1]){
	ch=a[j-1];
	a[j-1]=a[j];
	a[j]=ch;
	count++;
	flag=1;
      }
    }
  }

  for(j=0;j<N-1;j++){
    printf("%d ",a[j]);
  }
  printf("%d",a[N-1]);
  printf("\n");
  printf("%d\n",count);

  return 0;
}

