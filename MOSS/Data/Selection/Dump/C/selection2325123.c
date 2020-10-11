#include <stdio.h>
#define N 101

int a[N];
int count=0;

void swap(int *x,int *y){
  int t=*x;
  *x=*y;
  *y=t;
}

void selectionsort(int n){
  int i,j;
  for(i=0;i<n;i++){ // ??????????????¨???????????????????´???????
    int minj=i;
    for(j=i+1;j<n;j++){
      if(a[j]<a[minj]) minj=j;
    }
    if(i!=minj){
    swap(&a[i],&a[minj]);
    count++;
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
  
  selectionsort(n);
  for(i=0;i<n;i++){
    printf("%d",a[i]);
    if(i<n-1) printf(" ");
  }
  printf("\n%d\n",count);
  
  return 0;
}
