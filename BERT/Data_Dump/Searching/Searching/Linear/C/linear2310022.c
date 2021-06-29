#include <stdio.h>
int A[1000000],n;
int main(){
  int i,q,k,sum=0;
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&A[i]);
  }
  scanf("%d",&q);
  for(i=0;i<q;i++){
    scanf("%d",&k);
    if(linearSearch(k)==1){
      sum++;
    }
  }
  printf("%d\n",sum);
  return 0;
}
 
int linearSearch(int key){
  int a=0,b=n;
  while(a < b){
    if(key==A[a]){
      return 1;
    }
    a++;
  }
  return 0;
}
