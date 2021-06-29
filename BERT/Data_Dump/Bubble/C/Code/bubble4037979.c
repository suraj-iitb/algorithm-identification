#include<stdio.h>
int main(){
  int N,a[100],i,j;
  int t,c=0;
  scanf("%d",&N);
  
  for(i=0;i<N;i++){
    scanf("%d",&a[i]);
  }
  
  for(i=0;i<N-1;i++){
    for(j=N-1;j>i;j--){
      if(a[j]<a[j-1]){
	t=a[j];
	a[j]=a[j-1];
	a[j-1]=t;
	c++;
      }
    }
  }

  for(i=0;i<N;i++){
    printf("%d",a[i]);
    if(i<N-1)printf(" ");
  }
  printf("\n%d\n",c);
  return 0;
}

