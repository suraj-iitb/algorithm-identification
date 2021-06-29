#include<stdio.h>
#define N 100
int bubbleSort(int*,int);

int main(){
  int i,n,count,a[N];
  
  scanf("%d",&n);
  for(i=0; i<n; i++) 
    scanf("%d",&a[i]);

  count=bubbleSort(a,n);
  for(i=0; i<n; i++) {
    printf("%d",a[i]);
    if(i<n-1) printf(" ");
  }
  printf("\n%d\n",count);
  
  return 0;
}

int bubbleSort(int a[],int n)
{
  int flag = 1; 
  int i=0,j,tmp,count=0;
  
  while(flag) {
    flag = 0;
    for(j=n-1; j>i; j--) {
      if(a[j]<a[j-1]) {
	tmp = a[j];
	a[j] = a[j-1];
	a[j-1] = tmp;
	flag = 1;
	count++;
      }
    }
    i++;
  }
  return count;
}
