#include <stdio.h>

int main(){
  int n,a[100];
  int i,j,k;
  int flag=1;
  int count=0;

  scanf("%d",&n);
  for(i = 0; i < n; i++)
    scanf("%d",&a[i]);

  while(flag){
    flag = 0;
    for(j = n-1; j > 0 ; j--){
      if(a[j] < a[j-1]){
	k = a[j];
	a[j] = a[j-1];
	a[j-1] = k;
	count++;
	flag = 1;
      }
    }
  }
  for(i = 0; i < n-1; i++)
    printf("%d ",a[i]);
  printf("%d",a[n-1]);
  printf("\n%d\n",count);
}