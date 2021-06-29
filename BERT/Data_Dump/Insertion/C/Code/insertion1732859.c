#include <stdio.h>
int main()
{
  int i,n,array[100],t,y,j;
  
  scanf("%d\n",&n);
  
  for(i=0;i<n;i++){
    scanf("%d", &array[i]);
    
    printf("%d", array[i]);
    if(i<n-1){
      printf(" ");
    }
  }
  printf("\n");

  
  for(i=1;i<=n-1;i++){
    t=i;

    while(t > 0 && array[t] < array[t-1]){
      y=array[t];
      array[t]=array[t-1];
      array[t-1]=y;
      t--;
    } 
    for(j=0;j<=n-1;j++){

      printf("%d", array[j]);
      if(j <= n-2){
	printf(" ");
      }
    }
    printf("\n");
  }
  
  return 0;
}
