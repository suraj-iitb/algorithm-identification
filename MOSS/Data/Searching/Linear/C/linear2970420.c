#include<stdio.h>
#define nMax 10000
#define qMax 500

int linearSearch(int key,int S[],int n){
  int i;
  i=0;
  S[n] = key;
  while(S[i] != key){
    i++;
    if(i>=n){
      return 0;
    }
  }
  return 1;
}
  
int main(){

  int n,i,j,q,z,count=0;
  int S[nMax],T[qMax];

  scanf("%d",&n);

  if(n <= nMax){
    for(i=0;i<n;i++){
      scanf("%d",&S[i]);
    }
  }
  else printf("Not found\n");
  
    scanf("%d",&q);

    if(q <= qMax){
      for(j=0;j<q;j++){
	scanf("%d",&T[j]);
	if(linearSearch(T[j],S,n))
	  count++;	  
      }
    }
    else printf("Not found\n");

   

    printf("%d\n",count);

    return 0;
}

