#include<stdio.h>

int selectionsort(int a[],int n){
  int i,j;
  int minj;
  int esc;
  int count=0;
  for(i=0;i<n;i++){
    minj = i;
    for(j=i;j<n;j++){
      if(a[j]<a[minj]){
	minj = j;
      }
    }
    if(a[i]!=a[minj]){
      esc = a[i];
      a[i] = a[minj];
      a[minj] = esc;
      count++;
    }
  }
  return count;
}  


int main(void){
  int n;
  int a[100]={};
  int i;
  int count;
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&a[i]);
  }
  count = selectionsort(a,n);
  for(i=0;i<n;i++){
    printf("%d",a[i]);
    if(i!=n-1) printf(" ");
  }
  printf("\n%d\n",count);
  return 0;
}
