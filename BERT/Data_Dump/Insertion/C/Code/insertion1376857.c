#include<stdio.h>
int main(){
  int n,i,j,k,l;
  scanf("%d",&n);
  int a[n],temp;
  for(i=0;i<n;i++){
    scanf("%d",&a[i]);
  }
  for(i=0;i<n-1;i++){
    for(j=0;j<n;j++){
      printf("%d",a[j]);
      if(j!=n-1)printf(" ");
    }
    printf("\n");//最初の出力
    for(j=0;j<n-1;j++){
      if(a[i+1-j]<a[i-j] && i-j>=0){
	temp=a[i-j];
	a[i-j]=a[i+1-j];
	a[i+1-j]=temp;
      }
      else break;
    }
  }
  for(i=0;i<n;i++){
    printf("%d",a[i]);
    if(i!=n-1)printf(" ");
  }
  printf("\n");
  return(0);
}
