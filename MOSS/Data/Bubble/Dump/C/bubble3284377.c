#include<stdio.h>
int main(){
  int n,a[100],i,j,tmp,flag=1,sum=0;
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&a[i]);
  }
  while(flag){
    flag=0;
    for(j=n-1;j>=1;j--){
      if(a[j]<a[j-1]){
	sum++;
        tmp=a[j];
	a[j]=a[j-1];
	a[j-1]=tmp;
	flag=1;
      }
    }
  }
  for(i=0;i<n;i++){
    printf("%d",a[i]);
    if(i==n-1){
      printf("\n");
    }else{
      printf(" ");
    }
  }
  printf("%d\n",sum);
}

