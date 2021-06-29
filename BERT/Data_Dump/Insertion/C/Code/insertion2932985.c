#include<stdio.h>
#define NUM 1000

int main(){
  int i,j,k,num,n,v;
  int a[NUM];

  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&a[i]);
  }

  for(i=1;i<=n-1;i++){
    v=a[i];
    j=i-1;
    for(k=0;k<n;k++){
      if(k!=0)
	printf(" ");
      printf("%d",a[k]);
    }
    printf("\n");
    while(j>=0 && a[j]>v){
      a[j+1]=a[j];
      j--;
      a[j+1]=v;
    }
  }
  for(k=0;k<n;k++){
    if(k!=0)
      printf(" ");
      printf("%d",a[k]);
  }
  printf("\n");
  
  return 0;
  
  
}

