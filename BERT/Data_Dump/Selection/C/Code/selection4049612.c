#include <stdio.h>
#define N 100

void selectionsort(int[],int);

int main(){
  int a[N],n,i;

  scanf("%d",&n);

  for(i=0;i<n;i++){
    scanf("%d",&a[i]);
  }
  selectionsort(a,n);

  return 0;
}

void selectionsort(int a[],int n){
  int key=0;
  int i,j,minj,status;

  for(i=0;i<n-1;i++){
    minj=i;
    for(j=i;j<n;j++){
      if(a[j]<a[minj]){
	minj=j;
      }
    }
    status=a[i];
    a[i]=a[minj];
    a[minj]=status;
    if(i!=minj) key++;
  }

  for(i=0;i<n;i++){
    if(i>0) printf(" ");
    printf("%d",a[i]);
  }
  printf("\n%d\n",key);
}

