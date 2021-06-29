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

void selection(int a[], int n){
  int i, j, temp;
  int minj=-1;
  int cnt = 0;
  for(i=0; i<n; i++){
    minj = i;
    for(j=i; j<n; j++){
      if(a[j] < a[minj]){
        minj = j;
      }
    }
    if(i != minj){
      temp = a[i];
      a[i] = a[minj];
      a[minj] = temp;
      cnt++;
    }
  }
  show(a, n);
  printf("%d\n", cnt);
}

int main(){
  int n, i;
  int a[101];
  scanf("%d", &n);
  for(i=0; i<n; i++){
    scanf("%d", &a[i]);
  }
  selection(a, n);
  return 0;
}
