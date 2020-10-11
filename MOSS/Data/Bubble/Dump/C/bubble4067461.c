#include <stdio.h>
#include <stdlib.h>

int bubbleSort(int *,int);

int main()
{
  int n,*m,i,c,j;
  
  scanf("%d",&n);

  m = (int *)malloc(n * sizeof(int));

  for(i=0;i<n;i++){
    scanf("%d",&m[i]);
  }

  c = bubbleSort(m,n);

  for(j=0;j<n;j++){
    printf("%d",m[j]);
    if(j<n-1) printf(" ");
    else printf("\n");
  }
  printf("%d\n",c);

  free(m);

  return 0;
}

int bubbleSort(int *m,int n)
{
  int i,j,t,c=0;
  for(i=0;i<n;i++){
    for(j=n-1;j>i;j--){
      if(m[j-1]>m[j]){
	t = m[j-1];
	m[j-1] = m[j];
	m[j] = t;
	c++;
      }
    }
  }

  return c;
}



  
    

