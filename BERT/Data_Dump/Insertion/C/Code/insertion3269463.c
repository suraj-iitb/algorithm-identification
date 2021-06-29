#include <stdio.h>

#define N 100

void insertionSort(int[] ,int );
void trace(int [] ,int);

int main(){
  int n,i;
  int a[N];
  scanf("%d",&n);
  for(i=0;i<n;i++) {
    scanf("%d",&a[i]);
  }
  trace(a,n);
  insertionSort(a,n);
  return 0;
}

void insertionSort(int a[],int n){
int v;
int i,j;
  for(i=1;i<n;i++){
  v = a[i];
  j = i - 1;
  while(j >= 0 && a[j] > v){
    a[j+1] = a[j];
    j--;
  }
  a[j + 1] = v;
  trace(a,n);
  }
}

void trace(int a[],int n){
  int i;
  for(i=0;i<n;i++){
    if(i>0) printf(" ");
    printf("%d",a[i]);
  }
  printf("\n");
}

