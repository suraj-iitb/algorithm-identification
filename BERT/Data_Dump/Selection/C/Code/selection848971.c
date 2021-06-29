#include <stdio.h>

int main(){
  int i,j,n,count=0,mini;
  scanf("%d",&n);
  int a[n];

  for(i=0; i<n; i++)
    scanf("%d",&a[i]);
  
  for(i=0; i<n; i++){
    mini = i;
    for(j=i; j<n; j++)
      if(a[j] < a[mini])
	mini = j;
    if(mini != i){    
      int tmp = a[i];
      a[i] = a[mini];
      a[mini] = tmp;
      count++;
    }
  }
  
  for(i=0; i<n-1; i++)
    printf("%d ",a[i]);
  
  printf("%d\n%d\n",a[n-1],count);
  return 0;
}
