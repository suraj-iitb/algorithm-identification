#include<stdio.h>

int main(){
  int i,j,k,a[100],n,count=0,flag = 1;

  scanf("%d",&n);
  for(i = 0;i < n;i++){
    scanf("%d",&a[i]);
  }

  i = 0;
  while(flag){
    flag = 0;
    for(j = n - 1;j >= i + 1;j--){
      if(a[j] < a[j-1]){
	k = a[j];
	a[j] = a[j-1];
	a[j-1] = k;
	flag = 1;
	if(j < i + 1)break;
	count++;
      }
    }
    i++;
  }

  for(i = 0;;i++){
    printf("%d",a[i]);
    if(i >= n - 1)break;
    printf(" ");
  }
  printf("\n%d\n",count);

  return 0;
}
