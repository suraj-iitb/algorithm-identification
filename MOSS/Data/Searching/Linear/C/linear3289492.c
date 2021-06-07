#include <stdio.h>
#define NOT_FOUND -1


int linerSearch(int,int,int *);
int main(){
  int A[10000];
  int a,i,b,n,n2,n3,count = 0;
  
  scanf("%d",&n);
  for(i=0;i<n;i++)scanf("%d",&A[i]);

  scanf("%d",&n2);
  for(i=0;i<n2;i++){scanf("%d",&b);
 
 
    a = linerSearch(b,n,A);
    if(a != NOT_FOUND)count++;
    else continue;
  } printf("%d\n",count);
  return 0;
 
}

int linerSearch(int key,int n,int A[]){
  int i=0;
  
  A[n]=key;
  while(A[i]!=key){
    i++;
    if(i==n)return NOT_FOUND;
  }
  return i;
}

