#include <stdio.h>

int main()
{
  int g,w,h=0,i,j,f,y,d;
  int A[100000],B[50000];

  scanf("%d",&g);
  for(i=0; i<g; i++){
    scanf("%d",&A[i]);
  }

  scanf("%d",&w);
  for(i=0; i<w; i++){
    scanf("%d",&B[i]);
    f = 0;
    d = g;
    while(f<d){
      y = (f+d)/2;
      if(A[y]<B[i])
        f = y+1;
      if(A[y]==B[i]){
        h++;
        break;
      }
      if(A[y]>B[i])
        d = y;
    }
  }    
  printf("%d\n",h);

  return 0;
}

