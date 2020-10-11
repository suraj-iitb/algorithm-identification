#include<stdio.h>
#include<stdlib.h>

int main(){
  int i,*A,j,minj,n,hozon,count=0;
  scanf("%d",&n);

  A= (int *)malloc(n*sizeof(int));

  for(i=0;i<n;i++){
    scanf("%d",&A[i]);
  }

  for(i=0;i<n;i++){
    minj=i;
    for(j=i;j<n;j++){
      if (A[j]<A[minj]) minj=j;
    
    }
    if(i!=minj)    count++;
    hozon=A[i];
    A[i]=A[minj];
    A[minj]=hozon;
     
    
  }

  for(i=0;i<n;i++){
    printf("%d",A[i]);
    if(i!=n-1) printf(" ");
    else printf("\n");
  }

  printf("%d\n",count);
  return 0;
}

