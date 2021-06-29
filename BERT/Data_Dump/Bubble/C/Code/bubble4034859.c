#include <stdio.h>

#define NUM 100

int main()
{
  int n,i,j,k,l = 0,flag;
  int a[NUM];

  scanf("%d",&n);

  for(i = 0;i < n;i++){
    scanf("%d",&a[i]);
  }
  flag = 1;
  while(flag){
    flag = 0;
    for(j = i - 1;j > 0;j--){
      if(a[j] < a[j-1]){
	k = a[j-1];
	a[j-1] = a[j];
	a[j] = k;
	flag = 1;
	l++;
      }
    }
  }
  printf("%d",a[0]);
  for(i = 1;i < n;i++){
    printf(" %d",a[i]);
  }
  printf("\n");
  printf("%d\n",l);

  return 0;
}

      

