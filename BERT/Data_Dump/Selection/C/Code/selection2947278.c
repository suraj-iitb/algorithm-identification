#include<stdio.h>
#define NUM 100

int main(){
  int i,j,n,count,minj,hoji;
  int a[NUM];

  scanf("%d",&n);

  for(i=0;i<n;i++){
    scanf("%d",&a[i]);
  }

  for(i=0;i<=n-1;i++){
    minj=i;
    for(j=i;j<=n-1;j++){
      if(a[j]<a[minj]){
	minj=j;
      }
    }
    if(i!=minj){
      hoji=a[i];
      a[i]=a[minj];
      a[minj]=hoji;
      count++;
    }
  }

  for(i=0;i<n;i++){
    if(i!=n && i!=0){
      printf(" ");
    }
    printf("%d",a[i]);
  }

  printf("\n%d\n",count);

  return 0;
}

