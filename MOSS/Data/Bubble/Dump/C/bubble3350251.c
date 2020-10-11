#include<stdio.h>
#define A 100

int sw=0;

void bubblesort(int *a, int n){
  int tmp,flag=1,i;

  while(flag==1){
    flag=0;

    for(i=n-1;i>0;i--){
      if(a[i]<a[i-1]){
        tmp=a[i];
        a[i]=a[i-1];
        a[i-1]=tmp;
        flag=1;
        sw++;
      }
    }
  }
}

void print(int *a, int n){
  int i;

  for(i=0;i<n-1;i++) printf("%d ",a[i]);
  printf("%d\n%d\n",a[i],sw);
}

int main(){
  int tmp,flag=1,i,a[A],n,sw=0;

  scanf("%d",&n);
  for(i=0;i<n;i++) scanf("%d",&a[i]);

  bubblesort(a,n);
  print(a,n);

  return 0;
}


