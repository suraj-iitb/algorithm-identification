#include<stdio.h>

int main(){
  int n,i,j,max=0,A,C[100001];
  
  scanf("%d",&n);

  for(i=0;i<=10000;i++){
    C[i]=0;
  }

  for(i=0;i<n;i++){
    scanf("%d",&A);
    if(max<A)
      max=A;

    C[A]++;
  }


  for(i=0;i<max;i++){
    if(C[i]>0){
      for(j=0;j<C[i];j++){
	printf("%d ",i);
      }
    }
  }

  if(C[max]>1){
    for(i=0;i<C[max]-1;i++){
      printf("%d ",max);
    }

    printf("%d\n",max);
  }

  else{
    printf("%d\n",max);
  }


  return 0;
}

