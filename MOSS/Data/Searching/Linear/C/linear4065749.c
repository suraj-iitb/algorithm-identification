#include <stdio.h>
#define N 10000
#define F 500

int main(){
  int array1[N];
  int array2[F];
  int i,j,a,b,cnt=0;

  scanf("%d",&a);
  for(i=0;i<a;i++){
    scanf("%d",&array1[i]);
  }

  scanf("%d",&b);
  for(i=0;i<b;i++){
    scanf("%d",&array2[i]);
  }

  for(i=0;i<b;i++){
    for(j=0;j<a;j++){
      if(array2[i]==array1[j]){ cnt++; break; }
    }
  }

  printf("%d\n",cnt);

  return 0;
}

