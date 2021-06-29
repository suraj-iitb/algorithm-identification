#include <stdio.h>

int linearSearch(int A[],int n,int key);

int main (void)
{
  int i,n;
  int A[10001];
  int q,key;
  int s=0;
  
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&A[i]);
    }
    
  scanf("%d",&q);
  for(i=0;i<q;i++){
    scanf("%d",&key);
    
    if(linearSearch(A,n,key)){
      s++;
      }
  }
  
  printf("%d\n",s);
  
  return 0;
}

int linearSearch(int A[],int n,int key)
{
  int i=0;
  A[n]=key;
  
  while(A[i]!=key){
      i++;
      }
  return i!=n;
}
