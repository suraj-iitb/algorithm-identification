#include<stdio.h>

#define X 10000
#define Y 500

int ls(int,int);

int A[X],B[Y];

int ls(int i,int n){
  int j;
 A[n]=B[i];
    for(j=0;A[j]!=B[i];j++);
    if(j==n)return 0;
    else return 1;
}

int main(){
  int i,j,n,q,k=0;

  scanf("%d",&n);
  for(i=0;i<n;i++)scanf("%d",&A[i]);
  scanf("%d",&q);
  for(i=0;i<q;i++)scanf("%d",&B[i]);
  for(i=0;i<q;i++)
    k+=ls(i,n);

  printf("%d\n",k);
}



