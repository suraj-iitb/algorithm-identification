#include<stdio.h>
int main(void){
  int i,j,c=0;
  int N1,N2;
  int A[10000];
  int B[500];

  scanf("%d",&N1);
  for(i=0;i<N1;i++){
    scanf("%d",&A[i]);
  }

  scanf("%d",&N2);
  for(i=0;i<N2;i++){
    scanf("%d",&B[i]);
  }

  for(i=0;i<N1;i++){
    for(j=i+1;j<N1;j++){
      if(A[i]==A[j])A[j]=0;
    }
  }

  for(i=0;i<N1;i++){
    if(i!=0&&A[i]==0)continue;
    for(j=0;j<N2;j++){
      if(A[i]==B[j]){
	c++;
      }
    }
  }

  printf("%d\n",c);
  return 0;
}
