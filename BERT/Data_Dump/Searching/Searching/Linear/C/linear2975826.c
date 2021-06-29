#include<stdio.h>
#define N 10000
#define Q 500

int search(int A[],int n,int k){
  int i=0;

  A[n]=k;
  while(A[i]!=k)i++;
  return i!=n;
}

main(){
  int n,q;
  int A[N];
  int i,k;
  int c=0;

  scanf("%d",&n);
  for(i=0;i<n;i++)scanf("%d",&A[i]);
  scanf("%d",&q);
  for(i=0;i<q;i++){
    scanf("%d",&k);
    if(search(A,n,k))c++;
  }

  printf("%d\n",c);

  return 0;

}


