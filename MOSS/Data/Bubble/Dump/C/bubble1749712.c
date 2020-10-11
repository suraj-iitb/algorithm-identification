#include<stdio.h>
int main(){

  int N,a[100],i,flag,alternative,counter=0;

  scanf("%d",&N);
  for(i=0;i<N;i++){
    scanf("%d",&a[i]);
  }

  flag=1;
  while(flag){
    flag=0;
    for(i=N-1;1<=i;i--){
      if(a[i]<a[i-1]){
	alternative=a[i];
	a[i]=a[i-1];
	a[i-1]=alternative;
	flag=1;
	counter=counter+1;
      }
    }
  }

  for(i=0;i<N-1;i++){
    printf("%d ",a[i]);
  }
  printf("%d\n",a[i]);
  printf("%d\n",counter);

  return 0;
}
