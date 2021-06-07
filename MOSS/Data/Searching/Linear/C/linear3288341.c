#include<stdio.h>

int main(){
  int n,i,A[10000],q,j,cnt=0;

  scanf("%d",&n);
  for(i=0; i<n; i++){
    scanf("%d",&A[i]);
  }

  scanf("%d",&q);
  for(j=0; j<q; j++){
    //linearSearch
    i=0;
    scanf("%d",&A[n]);
    while(A[i]!=A[n])i++;
    if(i<n)cnt++;
  }

  printf("%d\n",cnt);

  return 0;
}

