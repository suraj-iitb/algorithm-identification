#include<stdio.h>
int a[100],n;
void insertionSort(){
  int i,v,j;
  for(i=1;i<n;++i){
    v=a[i];
    j=i-1;
    while(j>=0&&a[j]>v){
      a[j+1]=a[j];
      --j;
    }
    a[j+1]=v;
    for(j=0;j<n;++j){
      if(j) printf(" ");
      printf("%d",a[j]);
    }
    printf("\n");
  }
}
int main(){
  int i;
  scanf("%d",&n);
  for(i=0;i<n;++i) scanf("%d",&a[i]);
  for(i=0;i<n;++i){
    if(i) printf(" ");
    printf("%d",a[i]);
  }
  printf("\n");
  insertionSort();
  return 0;
}

