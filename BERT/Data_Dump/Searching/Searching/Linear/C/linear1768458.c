#include <stdio.h>
#define N 10000
#define Q 500
int S[N],T[Q],n;
int main(){
  int i,q,Sum=0;
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&S[i]);
  }
  scanf("%d",&q);
  for(i=0;i<q;i++){
    scanf("%d",&T[i]);
  }
  for(i=0;i<q;i++){
    if(linear(T[i]))
      Sum++; 
  }    
  printf("%d\n",Sum);
  return 0;
}
int linear(int key)
{
  int i=0;
  S[n]=key;
  while(S[i]!=key)i++;
  if(i==n){
    return 0;
  }
  else return 1;
}
