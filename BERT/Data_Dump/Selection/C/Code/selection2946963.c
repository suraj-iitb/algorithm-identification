#include<stdio.h>
#define N 100


int main()
{
  int i,j,a[N],n,v,c = 0,min,flag = 0;
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&a[i]);
  }
  for(i=0;i<=n-1;i++){
    min = i;
    flag = 0;
    for(j=i;j<n;j++){
      if(a[j]<a[min]){
	min = j;
	flag = 1;
      }/* 最小値の変更 */
    }
    if(flag == 1){
      v = a[i];
      a[i] = a[min];
      a[min] = v;	
      c++;
    }/* 最小値が変った場合、値を交換 */
  }
  
  for(i=0;i<n;i++){
    printf("%d",a[i]);
    if(i<n-1)printf(" ");
  }
  printf("\n");
  printf("%d\n",c);
  return 0;
}


