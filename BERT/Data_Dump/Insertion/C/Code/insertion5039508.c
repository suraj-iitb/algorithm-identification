#include<stdio.h>
#include<stdlib.h>
int main(){

  int *a,i,j,b,N,k;

  scanf("%d",&N);
  a=(int *)malloc(N*sizeof(int));
  for(j=0;j<N;j++){
    scanf("%d",&a[j]);
  }
  for(j=1;j<N;j++){
    for(k=0;k<N;k++){
        printf("%d",a[k]);
	if(k !=N-1)printf(" ");
    }
    printf("\n");
    for(i=j-1;i>=0;i--){
      if(a[i]>a[i+1]){
	b=a[i];
	a[i]=a[i+1];
	a[i+1]=b;   
      }     
    }   
  }
  for(j=0;j<N;j++){
    printf("%d",a[j]);
    if(j !=N-1)printf(" ");
  }
  printf("\n");
  return 0;  
}


