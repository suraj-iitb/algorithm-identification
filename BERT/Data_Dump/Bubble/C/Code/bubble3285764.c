#include<stdio.h>
#include<stdlib.h>

void bubbleSort(int *,int);
int main(){
  int n,num,i,j;
  int a[110];
  scanf("%d",&n);
  for(i = 0;i < n;i++){
    scanf("%d",&a[i]);
  }
  bubbleSort(a,n);
  return 0;
}

void bubbleSort(int *a, int n){
  int v,i,j;
  int flag = 1,cnt = 0;
  while(flag){
    flag =0;
    for(j = n - 1; j > 0; j--){
      if(a[j] < a[j-1]){
        v = a[j];
        a[j] = a[j-1];
        a[j-1] = v;
        flag = 1;
        cnt++;
      }
    }
  }
  for(j = 0; j < n; j++){
    if(j)printf(" ");
      printf("%d",a[j]);
  }
  printf("\n%d\n",cnt);
  return;
}

