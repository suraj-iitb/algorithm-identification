#include <stdio.h>
#include <stdlib.h>

int main(void)
{
  int n;
  int *a;
  int i,j,k;
  int v;
  
  scanf("%d",&n);

  a = (int *)malloc(sizeof(int) * n);

  for(i=0; i<n; i++){
    scanf("%d",&a[i]);
  }

  for(i=1; i<n; i++){

    for(k=0; k<n; k++){
      printf("%d",a[k]);
      if(k != (n-1)){
	printf(" ");
      }
    }
    puts("");
    
    v=a[i];
    j=i-1;
    while((j>=0) && (a[j] > v)){
      a[j+1] = a[j];
      j--;
    }
    a[j+1] = v;
  }

  for(k=0; k<n; k++){
    printf("%d",a[k]);
    if(k != (n-1)){
      printf(" ");
    }
  }
  puts("");

  free(a);
  
  return(0);
}
