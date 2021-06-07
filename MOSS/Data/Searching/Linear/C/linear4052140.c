#include<stdio.h>
#include<stdbool.h>
bool linearSearch(int[],int,int);
int main(){
  int count,n,A[10000],m,z,i;
  count=0;
  scanf("%d",&m);
  for(i=0;i<m;i++){
    scanf("%d",&A[i]);
  }
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&z);
    if(linearSearch(A,m,z))
      count++;
  }
  printf("%d\n",count);
  return 0;
}
bool linearSearch(int *A,int n,int key){
  int i=0;
  while(A[i]!=key){
    i++;
    if(i==n)
      return false;
  }
  return true;
}

