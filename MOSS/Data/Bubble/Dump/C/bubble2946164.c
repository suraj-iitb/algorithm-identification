#include<stdio.h>
#include<stdlib.h>

int main(){
  int i,j;
  int N;
  int KTK;
  int count=0;
  int Alength;
  
  scanf("%d",&N);
  //if(N>100||N<1){
  //  printf("N is wrong\n");
  //  exit(0);
  //}
  
  int A[N];
  
  Alength = sizeof(A)/sizeof(int);
  
  for(i=0;i<=Alength-1;i++){
    scanf(" %d",&A[i]);
  }

  A[Alength]='\0';

  for(i=0;i<=Alength-1;i++){
    for(j=Alength-1;j>=i+1;j--){
      if(A[j]<A[j-1]){
	KTK=A[j];
	A[j]=A[j-1];
	A[j-1]=KTK;
	count++;
      }
    }
  }

  for(i=0;i<Alength-1;i++){
    printf("%d ",A[i]);
  }
  printf("%d",A[i]);
  printf("\n");
  printf("%d\n",count);

  return 0;
}
	

