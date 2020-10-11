#include <stdio.h>

int main(){

  int n,i,j,minj,temp,sum = 0,sita = 0;
  int a[124] = {};
  

  
  scanf("%d",&n);

  for(i = 0;i < n;i++) scanf("%d",&a[i]);
  
  for(i = 0;i <= n - 1;i++){
    minj = i;
    for(j = i;j <= n - 1;j++){
      if(a[j] < a[minj]){
	minj = j;
      }
    }
    // printf("a[i] = %d,a[minj] = %d\n",a[i],a[minj]);
      if(i != minj){
	temp = a[i];
	a[i] = a[minj];
	a[minj] = temp;
	sum++;
      }
  }
  for(i = 0;i < n;i++){
    if(i != n - 1)printf("%d ",a[i]);
    else printf("%d",a[i]);
  }
  printf("\n");
  printf("%d\n",sum);
  return 0;
}
