#include <stdio.h>

int main(){
  int n,a[100];
  int i,j,k;
  int minj;
  int count=0;
  int flag;

  scanf("%d",&n);
  for(i = 0; i < n; i++)
    scanf("%d",&a[i]);

  for(i = 0; i < n; i++){
    flag = 0;
    minj = i;
    for(j = i; j < n; j++){
      if(a[j] < a[minj]){
	minj = j;
	flag = 1;
      }
    }
    k = a[i];
    a[i] = a[minj];
    a[minj] = k;
    if(flag) count++;
  }

  for(i = 0; i < n-1; i++)
    printf("%d ",a[i]);
  printf("%d",a[n-1]);
  printf("\n%d\n",count);
}
