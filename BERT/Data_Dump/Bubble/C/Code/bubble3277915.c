#include<stdio.h>
#include<stdlib.h>

int  BubbleSort(int *,int);

int main(){
  int swcut=0;
  int n,*a,i;
  
  scanf("%d",&n);
  a=(int *)malloc(n*sizeof(int));
  for(i=0;i<n;i++){
    scanf("%d",&a[i]);
  }

  swcut=BubbleSort(a,n);

  for(i=0;i<n;i++){
  printf("%d",a[i]);
  if(i!=n-1) printf(" ");
  }
  printf("\n%d\n",swcut);
  
  return 0;
}

int BubbleSort(int *a,int n){
  int i,j,stock,count=0;

  for(i=0;i<n;i++){
    for(j=n-1;j>0;j--){
      if(a[j]<a[j-1]){
        stock=a[j];
        a[j]=a[j-1];
        a[j-1]=stock;
        count++;
      }
    }
  }

  return count;
}

