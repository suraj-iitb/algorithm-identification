#include<stdio.h>
#define MAX 10000
#define MAX2 500

int linearSearch(int ,int *,int );

int main()
{
  int i,N,M,count=0;
  int A[MAX],key;

  scanf("%d",&N);
  
  if(N<=MAX){

    for(i=0;i<N;i++) scanf("%d",&A[i]);

  }

    scanf("%d",&M);

    if(M<=MAX2){

      for(i=0;i<M;i++){

      scanf("%d",&key);

      if(linearSearch(N,A,key)) count++;

	}

    }

    printf("%d\n",count);

    return 0;
}

int linearSearch(int N,int A[],int key){

      int i;

      i=0;
      A[N]=key;

      while(A[i]!=key){

	i++;

	if(i==N) return 0;

      }

	return 1;
}
