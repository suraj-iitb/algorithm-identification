#include <stdio.h>
#define N 100000

int search(int array[],int x,int n){
  int i = 0;
  array[n] = x;
  while(array[i] != x) i++;
  return i != n;
}


int main(){
  int S[N],key;
  int n,q;
  int i;
  int count = 0;

  scanf("%d",&n);
  for(i=0;i<n;i++)scanf("%d",&S[i]);
  
  scanf("%d",&q);
  for(i=0;i<q;i++){
    scanf("%d",&key);
    if(search(S,key,n)!=NULL)count++;
  }

  printf("%d\n",count);
  
  return 0;
}


