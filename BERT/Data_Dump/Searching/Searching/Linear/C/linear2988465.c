#include <stdio.h>

int main()
{
  int g,w,h=0,i,j;
  int A[10000],B[500];
  scanf("%d",&g);
  for(i=0; i<g; i++){
    scanf("%d",&A[i]);
  }
  scanf("%d",&w);
  for(i=0; i<w; i++){
    scanf("%d",&B[i]);
  }
  for(i=0; i<w; i++){
    for(j=0; j<g; j++){
      if(B[i]==A[j]){
        h++;
        break;
      }
    }
  }
  printf("%d\n",h);
  return 0;
}

