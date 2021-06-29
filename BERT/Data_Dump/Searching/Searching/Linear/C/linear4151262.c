#include<stdio.h>
#define M 10000

int search(int A[],int se,int n){
  int i;

  for(i = 0;i<n;i++){
    if(A[i]==se)return 1;
  }
  return 0;
}


int main(){
  int i,q,n,A[M+1],se,count=0,g;

  scanf("%d",&n);
  if(n>M)return 0;

  for(i =0;i<n;i++)
    scanf("%d",&A[i]);
  
  scanf("%d",&q);
  if(q>500) return 0;

  for(i = 0;i<q;i++){
    scanf("%d",&se);
    g = search(A,se,n);
    if(g == 1) count++;
  }
  printf("%d\n",count);
  return 0;

}

