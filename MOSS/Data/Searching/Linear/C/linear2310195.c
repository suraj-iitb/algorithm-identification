#include <stdio.h>
int Lsearch(int[],int,int);
int main(){
  int i,j,n,A[10000+1],sum=0,key;

  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&A[i]);
  }

  

  scanf("%d",&j);
  for(i=0;i<j;i++){
    scanf("%d",&key);
    if(Lsearch(A,n,key))sum++;
  }
  printf("%d\n",sum);
  return 0;
}

int Lsearch(int A[], int n, int key){
  int i=0;
  A[n]=key;
  while(A[i]!=key)i++;
  if(i==n)return 0;
  else return 1;
}
 
