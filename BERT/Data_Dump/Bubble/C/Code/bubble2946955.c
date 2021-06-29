#include<stdio.h>
#define N 100


int main()
{
  int i,j,a[N],n,v,c = 0;
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&a[i]);
  }
  for(i=0;i<=n-1;i++){
    for(j=n-1;j>=i+1;j--){
      if(a[j]<a[j-1]){
	v = a[j];
	a[j] = a[j-1];
	a[j-1] = v;
	c++;
      }/* 隣あう値が後ろ側に小さい値がある場合交換する */
    }/* n個目から交換の終っているi番目迄実行する */
  }
  for(i=0;i<n;i++){
    printf("%d",a[i]);
    if(i<n-1)printf(" ");
  }
  printf("\n");
  printf("%d\n",c);
  return 0;
}


