#include<stdio.h>
#define MAX 100000
#define MAX2 50000

int binarySearch(int ,int *,int );

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

      if(binarySearch(N,A,key)!=-1) count++;

	}

    }

    printf("%d\n",count);

    return 0;
}

int binarySearch(int N,int A[],int key){

  int left,right,mid;

  left=0;

  right=N;

  while(left<right){

    mid=(double)(left+right)/2;

    if(key==A[mid]) return mid;

    if(key>A[mid]) left=mid+1;
    else if(key<A[mid]) right=mid;

  }

    return -1;
}
