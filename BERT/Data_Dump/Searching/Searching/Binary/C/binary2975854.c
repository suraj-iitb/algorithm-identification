#include<stdio.h>
#define N 100000
#define Q 50000

int A[N],n;

int search(int k){
  int l,r,m;

  l=0;r=n;

  while(l<r){
    m=(l+r)/2;
    if(k==A[m])return 1;
    if(k>A[m])l=m+1;
    else if(k<A[m])r=m;
  }
  return 0;
}

main(){
  int i,q,k;
  int c=0;

  scanf("%d",&n);
  for(i=0;i<n;i++)scanf("%d",&A[i]);

  scanf("%d",&q);
  for(i=0;i<q;i++){
    scanf("%d",&k);
    if(search(k))c++;
  }

  printf("%d\n",c);

  return 0;

}

