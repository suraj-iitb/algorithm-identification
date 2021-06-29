#include <stdio.h>
#define N 101

int a[N];
int count=0;

void swap(int *x,int *y){
  int t=*x;
  *x=*y;
  *y=t;
}

void bubblesort(int n){
  int i;
  for(i=0;i<n;i++){ // ??????????????¨???????????????????´???????
    int j;
    for(j=n-1;j>i;j--){
      if(a[j]<a[j-1]){
	swap(&a[j],&a[j-1]);
	count++;
      }
    }
  }
}

int main()
{
  int n;
  scanf("%d",&n);
  int i;
  for(i=0;i<n;i++){
    scanf("%d",&a[i]);
  }
  
  bubblesort(n);
  for(i=0;i<n;i++){
    printf("%d",a[i]);
    if(i<n-1) printf(" ");
  }
  printf("\n%d\n",count);
  
  return 0;
}
