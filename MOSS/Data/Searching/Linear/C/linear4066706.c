#include <stdio.h>
#include <stdlib.h>

int Search(int *,int *,int,int);

int main()
{
  int n1,n2,*a,*b,i,n;
  
  scanf("%d",&n1);

  a = (int *)malloc(n1 * sizeof(int));

  for(i=0;i<n1;i++){
    scanf("%d",&a[i]);
  }

  scanf("%d",&n2);

  b = (int *)malloc(n2 * sizeof(int));

  for(i=0;i<n2;i++){
    scanf("%d",&b[i]);
  }

  n = Search(a,b,n1,n2);

  printf("%d\n",n);

  free(a);
  free(b);

  return 0;
}

int Search(int *a,int *b,int n1,int n2)
{
  int c=0,i,j;

  for(i=0;i<n2;i++){
    j=0;
    while(1){
      if(a[j]==b[i]){
	c++;
	break;
      }
      if(j==n1-1) break;
      j++;
    }
  }

  return c;
}

