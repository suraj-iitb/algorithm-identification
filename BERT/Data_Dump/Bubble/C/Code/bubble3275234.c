#include<stdio.h>
#define N 100
int main(){
  int n,a[N],v,i,j,k,flag,count;
  flag = 1;
  count = 0;
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&a[i]);
      }
  while(flag){
    flag=0;
    for(j=n-1;j>=1;j--){
      if(a[j]<a[j-1]){
	v=a[j];
	a[j]=a[j-1];
	a[j-1]=v;
	count++;
	flag =1;
      }
    }
  }
  for(k=0;k<n;k++){
      printf("%d",a[k]);
      if(k != n - 1)printf(" ");
      else printf("\n");
    }
  printf("%d\n",count);
  return 0;
}

