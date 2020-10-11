#include<stdio.h>

int bubblesort(int a[],int n){
  int flag=1;
  int esc;
  int j;
  int count=0;
  while(flag){
    flag = 0;
    for(j=n-1;j>=1;j--){
      if(a[j]<a[j-1]){
	esc = a[j];
	a[j] = a[j-1];
	a[j-1] = esc;
	flag = 1;
	count++;
      }
    }
  }
  return count;
}


int main(void){
  int n,i;
  int a[100]={};
  int count;
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&a[i]);
  }
  count = bubblesort(a,n);
  for(i=0;i<n;i++){
    printf("%d",a[i]);
    if(i!=n-1) printf(" ");
  }
  printf("\n%d\n",count);
  return 0;
}
