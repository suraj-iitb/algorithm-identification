#include <stdio.h>
#define Max 10000
int main(){
  int i,T[Max],S[Max],k,j=0,count=0,n;
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&T[i]);
  }
  scanf("%d",&k);
  for(i=0;i<k;i++){
    scanf("%d",&S[i]);
  }
  for(i=0;i<k;i++){
    j=0;
    T[n]=S[i];
    while(T[j] != S[i]){
      j++;
    }
    if(j != n) count++; 
  }
  printf("%d\n",count);
  return 0;
}
