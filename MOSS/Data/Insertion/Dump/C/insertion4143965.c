#include <stdio.h>
#define N 100

int main(){
  int i,A[N],a,v,j,b;
  scanf("%d",&a);
  for(i=0;i<a;i++){
    scanf("%d",&A[i]);
  }
  for(i=1;i<a;i++){
    for(b=0;b<a;b++){
      if(b==a-1)printf("%d\n",A[b]);
      else printf("%d ",A[b]);
    }
    v=A[i];
    j=i-1;
    while(j>=0 && A[j]>v){
      A[j+1]=A[j];
      j--;
      A[j+1]=v;
    }
  }
    for(b=0;b<a;b++){
      if(b==a-1)printf("%d\n",A[b]);
      else printf("%d ",A[b]);
    }
  return 0;
}


