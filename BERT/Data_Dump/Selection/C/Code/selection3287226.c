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
  int min,cnt = 0;
  for(i = 0; i < n-1; i++){
    min =i;
    for(j = i; j < n; j++){
      if(a[j] < a[min]) min = j;
    }
    v = a[i];
    a[i] = a[min];
    a[min] = v;
    if(i != min)cnt++;
  }
  for(j = 0; j < n; j++){
    if(j)printf(" ");
      printf("%d",a[j]);
  }
  printf("\n%d\n",cnt);
  return;
}

