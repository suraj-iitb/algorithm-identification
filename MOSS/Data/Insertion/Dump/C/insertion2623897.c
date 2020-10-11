#include<stdio.h>

void show(int a[], int n){
  int i;
  for(i=0; i<n-1; i++){
    printf("%d ", a[i]);
  }
  printf("%d", a[n-1]);
  printf("\n");
  return ;
}

void insertion(int a[], int n){
  int i, j, temp;
  for(i=1; i<n; i++){
    temp = a[i];
    j = i - 1;
    while(j>=0 && a[j]>temp){
      a[j+1] = a[j];
      j--;
    }
    a[j+1] = temp;
    show(a, n);
  }
}

int main(){
  int n, i;
  int a[101];
  scanf("%d", &n);
  for(i=0; i<n; i++){
    scanf("%d", &a[i]);
  }
  show(a, n);
  insertion(a, n);
  return 0;
}
