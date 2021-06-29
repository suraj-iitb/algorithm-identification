#include <stdio.h>
#define N 100

int main()
{
  int a[N],n,i,j,mini,count=0;

  scanf("%d",&n);
  for(i = 0; i < n; i++){
    scanf("%d",&a[i]);
  }
  for(i = 0; i < n; i++){
    mini = i;
    for(j = i; j < n; j++){
      if(a[j] < a[mini])
	mini = j;
    }
    a[n] = a[i];
    a[i] = a[mini];
    a[mini] = a[n];
    if(i!=mini)
      count++;
  }
  for(i = 0; i < n; i++){
    if(i == n-1){
      printf("%d\n",a[i]);
      break;
    }
    printf("%d ",a[i]);
  }
  printf("%d\n",count);
  return 0;
}
