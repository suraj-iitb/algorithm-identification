#include<stdio.h>

void Print(int a[],int n){
  int i;
  for(i=0;i<n;i++){
    if(i>0) printf(" ");
    printf("%d",a[i]);
  }
  printf("\n");
}

void swap(int *x, int *y){
  int temp;
  temp= *x;
  *x= *y;
  *y=temp;


}

int  bubbleSort(int a[],int n){
  int i,flag,count;
  flag=1;
  count=0;
  while(flag){
    flag=0;
    for(i=n-1;i>0;i--){
      if (a[i] < a[i-1]){
      swap(&a[i],&a[i-1]);
      count++;
      flag=1;
    }
  }
}
return count;
}

int main(void){
  int n,i,count;
  int a[100];
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&a[i]);
  }
  count =bubbleSort(a,n);
  Print(a,n);
  printf("%d\n",count);

  return 0;
}

