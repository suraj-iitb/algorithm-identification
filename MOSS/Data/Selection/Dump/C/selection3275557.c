#include<stdio.h>
#define N 100
int main(){
  int n,a[N],v,i,j,k,count,minj,flag;
  count = 0;
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&a[i]);
      }
  for(i=0;i<=n-1;i++){
    flag = 0;
    minj = i;
    for(j=i;j<=n-1;j++){
      if(a[j]<a[minj]){
	minj = j;
	flag = 1;
      } 
    }
    if(flag){
      v=a[i];
    a[i]=a[minj];
    a[minj]=v;
    count++;
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

