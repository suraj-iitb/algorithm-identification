#include<stdio.h>
#include<stdlib.h>

int main(){
  int i,j;
  int N;
  int KTK,mini;
  int count=0;
  int Alength;
  
  scanf("%d",&N);
  
  int A[N];
  
  Alength = sizeof(A)/sizeof(int);
  
  for(i=0;i<=Alength-1;i++){
    scanf(" %d",&A[i]);
  }

  A[Alength]='\0';

  for(i=0;i<=Alength-1;i++){
    mini=i;
    for(j=i;j<=Alength-1;j++){
      if(A[j]<A[mini]){
	mini=j;
      }
    }
      KTK=A[mini];
      A[mini]=A[i];
      A[i]=KTK;
      if(A[i]!=A[mini])count++;
  }

  for(i=0;i<Alength-1;i++){
    printf("%d ",A[i]);
  }
  printf("%d",A[i]);
  printf("\n");
  printf("%d\n",count);

  return 0;
}

