#include <stdio.h>
#define MAX 100000
int main(){
  int a,b,A[MAX]={-1},B[MAX],count=0,i,j,c,t;
  scanf("%d",&a);
  scanf("%d",&A[0]);
  for(i=1,c=1;i<a;i++){
    scanf("%d",&t);
    if(A[c-1]<t){A[c]=t;c++;}
  }

  scanf("%d",&b);
  for(i=0;i<b;i++){
    scanf("%d",&B[i]);
  }
  i=c;
  for(i=0;i<b;i++){
    for(j=0;j<a;j++){
      if(A[j]==B[i]){count++;break;}
      if(A[j]>B[i]){break;}
    }
  }
  printf("%d\n",count);
  return 0;
}
