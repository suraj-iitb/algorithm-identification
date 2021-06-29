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

void bubble(int a[], int n){
  int flag = 1;
  int j, temp;
  int cnt = 0;
  while(flag){
    flag = 0;
    for(j=n-1; j>0; j--){
      if(a[j] < a[j-1]){
        temp = a[j];
        a[j] = a[j-1];
        a[j-1] = temp;
        cnt++;
        flag=1;
      }
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
  bubble(a, n);
  return 0;
}
