#include <stdio.h>
int SelectionSort(int *a,int b);

int main(int argc, const char * argv[]) {
  int a[100],n,i;
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&a[i]);
  }
  printf("%d\n",SelectionSort(&a,n));
}

int SelectionSort(int *a,int n){
  int i,j,tmp,minj,count=0;

  for(int i=0;i<n;i++){
    minj=i;
    for(j=i;j<n;j++){

      if(a[j]<a[minj]){
        minj=j;
      }

    }
    if(a[i]>a[minj]){
      tmp=a[minj];
      a[minj]=a[i];
      a[i]=tmp;
      count++;
    }
  }

  for(i=0;i<n-1;i++){
    printf("%d ",a[i]);
  }
  printf("%d\n",a[i]);
  return count;
}

