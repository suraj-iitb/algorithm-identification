#include<stdio.h>

int main(void){
  int n;
  scanf("%d", &n);
  int a[n];
  for(int i = 0; i<n; i++){
    scanf("%d", &a[i]);
  }
  int temp;
  int count =0;
  for(int i=0; i<n; i++){
    int minj = i;
    for(int j=i; j<n; j++){
      if(a[j]<a[minj]){
          minj = j;
      }


    }
    if(i!=minj){
      temp =a[i];
      a[i]=a[minj];
      a[minj]=temp;
      count++;
    }

  }

  for(int j=0; j<n-1; j++){
    printf("%d ",a[j]);
  }
  printf("%d\n", a[n-1]);
  printf("%d\n",count);

  return 0;
}

