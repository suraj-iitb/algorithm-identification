#include <stdio.h>
#include <stdlib.h>

int selectionSort(int *,int);

int main()
{
  int n,*m,i,c,j;
  
  scanf("%d",&n);

  m = (int *)malloc(n * sizeof(int));

  for(i=0;i<n;i++){
    scanf("%d",&m[i]);
  }

  c = selectionSort(m,n);

  for(j=0;j<n;j++){
    printf("%d",m[j]);
    if(j<n-1) printf(" ");
    else printf("\n");
  }
  printf("%d\n",c);

  free(m);

  return 0;
}

int selectionSort(int *m,int n)
{
  int i,j,minj,t,c=0;
  
  for(i=0;i<n;i++){
    minj = i;
    for(j=i;j<n;j++){
      if(m[j]<m[minj]){
	minj = j;
      }
    }
    if(i!=minj) c++;
    t = m[i];
    m[i] = m[minj];
    m[minj] = t;
  }

  return c;
}


    
      
      
  
  

