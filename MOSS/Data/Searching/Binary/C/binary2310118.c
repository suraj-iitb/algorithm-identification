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
    if(binarySearch(k)==1){
      sum++;
    }
  }
  printf("%d\n",sum);
  return 0;
}
 
int binarySearch(int key){
  int a=0,b=n,c;
  while(a < b){
    c=(a+b)/2;
    if(key==A[c]){
      return 1;
    }
    if(key>A[c]){
      a=c+1;
    }
    else if (key<A[c]){
      b=c;
    }
  }
  return 0;
}
