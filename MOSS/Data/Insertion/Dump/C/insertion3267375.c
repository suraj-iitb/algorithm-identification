#include<stdio.h>
#include<stdlib.h>

void insertionSort(int *,int);
int main(){
  int n,num,i,j;
  int a[110];
  scanf("%d",&n);
  for(i = 0;i < n;i++){
    scanf("%d",&a[i]);
  }
  insertionSort(a,n);
  return 0;
}

void insertionSort(int *a, int n){
  int v,i,j;
  if(n > 1){
    for(j = 0; j < n; j++){
        if(j)printf(" ");
	printf("%d",a[j]);
    }
    printf("\n");
    for(i = 1; i < n; i++){
      v = a[i];
      j = i -1;
      while(j >= 0 && a[j] > v){
	a[j + 1] = a[j];
	j--;
      }
      a[j+1] = v;

      for(j = 0; j < n; j++){
        if(j)printf(" ");
	printf("%d",a[j]);
      }
      printf("\n");
    }
  }
  else printf("%d\n",a[0]);
  return;
}


