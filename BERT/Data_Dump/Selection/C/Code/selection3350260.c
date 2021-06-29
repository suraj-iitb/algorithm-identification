#include<stdio.h>
#define A 100

int sw=0;

void selectionsort(int *a, int n){
  int i,j,tmp,minj;

  for(i=0;i<n-1;i++){
    minj=i;
    for(j=i;j<n;j++){
      if(a[j]<a[minj]) minj=j;
    }
    tmp=a[i];
    a[i]=a[minj];
    a[minj]=tmp;
    if(i!=minj) sw++;
  }
}

void print(int *a, int n){
  int i;

  for(i=0;i<n-1;i++) printf("%d ",a[i]);
  printf("%d\n%d\n",a[i],sw);
}

int main(){
  int i,n,a[A];

  scanf("%d",&n);
  for(i=0;i<n;i++) scanf("%d",&a[i]);

  selectionsort(a,n);
  print(a,n);

  return 0;
}
