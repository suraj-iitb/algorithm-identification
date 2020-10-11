#include <stdio.h>
int main(){
  int i,j,n,a[100],min,c=0,swap;

  scanf("%d",&n);
  for(i = 0; i < n; i++){
    scanf("%d",&a[i]);
  }

  for(i = 0; i < n; i++){
    min = i;
    for(j = i; j < n; j++){
      if(a[j] < a[min]){
	min = j;
      }
    }
    if(i != min) c++;
    
    swap = a[i];
    a[i] = a[min];
    a[min] = swap;
  }
  
  for( j = 0; j < n-1; j++){
    printf("%d ",a[j]);
  }
  printf("%d\n%d\n",a[n-1],c);

  
  return 0;
}
  
