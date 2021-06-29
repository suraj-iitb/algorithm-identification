#include <stdlib.h>
#include <stdio.h>

int search(int *,int *,int,int);

int main(){
  int i,n,q,*S,*T,count;

  scanf("%d",&n);

  S=(int *)malloc((n+1)*sizeof(int));
  for(i=0;i<n;i++){
    scanf("%d",&S[i]);
  }

  scanf("%d",&q);

  T=(int *)malloc(q*sizeof(int));
  for(i=0;i<q;i++){
    scanf("%d",&T[i]);
  }
 
  count=search(S,T,n,q);
  printf("%d\n",count);
  free(S);
  free(T);
  return 0;

    }

int search(int *S,int *T,int n,int q){
  int i, j=n,count=0;
  
  for(i=0;i<q;i++){
    if(j!=n){
      count++;
    }
    j=0;
    S[n]=T[i];
    while(S[j]!=S[n]){
      j++;
    if(j==n) break;
    }
  }
  if(j!=n){
      count++;
    }
  
  return count;
}

