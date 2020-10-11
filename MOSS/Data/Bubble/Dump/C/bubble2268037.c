#include<stdio.h>
int main(){
  int con,n,i,j,k,c=0,a[100],flag=1;
  scanf("%d",&n);
  for(k = 0;k < n;k++){
    scanf("%d",&a[k]);
  }
  while(flag){
    flag=0;
    for (j = n-1; j > 0; j--){
      if(a[j] < a[j-1]){
	con=a[j-1];
	a[j-1]=a[j];
	a[j]=con;
	c++;
	flag=1;
      }
    }
  }
  for (i = 0; i < n; i++) {
    if(i<n-1){
      printf("%d ",a[i]);
    }
    else if(i==n-1){
      printf("%d\n",a[i]);
    }
  }
  printf("%d\n",c);
  return 0;
}
