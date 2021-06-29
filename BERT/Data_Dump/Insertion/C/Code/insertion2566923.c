#include <stdio.h>

void insertionSort(int a[],int N){
  int i,j,k,temp;

  for(i=1;i<N;i++){
    temp=a[i];
    for(j=i;j>0&&a[j-1]>temp;j--){
      a[j]=a[j-1];
    }
    a[j]=temp;
    for(k=0;k<N;k++){
      if(k>0)printf(" ");
      printf("%d",a[k]);
    }
    printf("\n");
  }
}

int main(void){
  int n,a[1000],i;

  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&a[i]);
  }

  for(i=0;i<n;i++){
    if(i>0)printf(" ");
    printf("%d",a[i]);
  }
  printf("\n");

  insertionSort(a,n);

  return 0;
}
