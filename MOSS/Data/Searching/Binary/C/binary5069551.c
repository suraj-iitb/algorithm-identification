#include<stdio.h>
#include<stdlib.h>

void binarySearch(int * ,int);

int n,q;
int count=0;

int main(){
  
  int *N, *Q;
  int i;
  
  scanf("%d",&n);
  if(100000<n)exit(1);
  N=(int *)malloc(n*sizeof(int));

  for(i=0; i<n; i++){
    scanf("%d",&N[i]);
    if(N[i]<0 || 1000000000<N[i])exit(2);
  }

  scanf("%d",&q);
  if(50000<q)exit(3);
  Q=(int *)malloc(q*sizeof(int));

  for(i=0; i<q; i++){
    scanf("%d", &Q[i]);
    if(N[i]<0 || 1000000000<N[i])exit(4);
    //printf("b\n");
    binarySearch(N,Q[i]);
  }

  printf("%d\n",count);
  
  return 0;
}

void binarySearch(int *N,int Q){
  int left=0;
  int right=n;
  int mid;
  
  while(left < right){
    //printf("mid\n");
    mid=(left+right)/2;

    if(N[mid]==Q){
      count++;
      break;
    }
    else if(Q<N[mid])
      right=mid;
    else
      left=mid+1;
  }
}

