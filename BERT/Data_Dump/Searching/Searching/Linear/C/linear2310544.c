#include <stdio.h>
int Lsearch(int[],int,int);
int main(){
  int x,y,i,j,k,key,res=0,same[500],A[10000+1];

  scanf("%d",&x);
  for(i=0;i<x;i++){
    scanf("%d",&A[i]);
  }
  scanf("%d",&y);
  for(i=0;i<y;i++){
    scanf("%d",&key);
    if(Lsearch(A,x,key)==1)res++;
  }


  printf("%d\n",res);
  return 0;
}

int Lsearch(int B[],int n,int kkey){
  int i=0;
  B[n]=kkey;
  while(B[i]!=kkey) i++;
  if(i==n)return 0;
  else return 1;
}
