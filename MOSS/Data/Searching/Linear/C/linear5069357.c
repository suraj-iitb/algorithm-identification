#include<stdio.h>
#include<stdlib.h>

int linerSearch(int *,int *);

int n,q;

int main(){
  
  int *N,*Q;
  int i;

  scanf("%d",&n);
  if(10000<n)exit(1);
  N=(int *)malloc(n*sizeof(int));
  for(i=0; i<n; i++){
    scanf("%d",&N[i]);
    if(N[i]<0 || 1000000000<N[i])exit(2);
  }

  scanf("%d",&q);
  if(500<q)exit(3);
  Q=(int *)malloc(q*sizeof(int));
  for(i=0; i<q; i++){
    scanf("%d",&Q[i]);
    if(Q[i]<0 || 1000000000<Q[i])exit(4);
  }

  printf("%d\n",linerSearch(N,Q));

  return 0;
}

int linerSearch(int *N,int*Q){
  int i,j;
  int count=0;

  for(i=0; i<q; i++){
    for(j=0; j<n; j++){
      if(Q[i]==N[j]){
	count++;
	break;
      }
    }
  }

  return count;
}

