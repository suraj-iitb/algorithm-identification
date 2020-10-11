#include <stdio.h>

void insertionSort(int a[],int n){
  int i,j,k,temp;
  for(i=0;i<n;i++){
    temp = a[i];
    j = i-1;
    while(j>=0 && a[j]>temp){
      a[j+1] = a[j];
      j--;
    }
    a[j+1] = temp;
    for(k=0;k<n;k++){
      if(k<n-1){printf("%d ",a[k]);}
      else{printf("%d",a[k]);}
    }
    printf("\n");
  }
}

int main(){
  int i,n,a[100];
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&a[i]);
  }
  insertionSort(a,n);
  return 0;
}
