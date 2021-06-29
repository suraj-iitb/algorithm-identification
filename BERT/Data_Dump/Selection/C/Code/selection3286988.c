#include <stdio.h>

int main(){
  int i,j,flag,minj;
  int n,a;
  int count = 0;

  scanf("%d",&n);
  int data[n];
  for(i = 0;i < n;i++){
    scanf("%d",&a);
    data[i] = a;
  }

  for(i = 0;i < n-1;i++){
    int key;
    minj = i;
    flag = 0;
    for(j = i+1;j < n ;j++) {
      if(data[j] < data[minj]){
        minj = j;
	flag = 1;
      }
    }
      if(flag){
        key = data[minj];
        data[minj] = data[i];
        data[i] = key;
        count++;
      }
  }
  for(i = 0;i < n;i++){
  printf("%d",data[i]);
  if(i==n-1) break;
  printf(" ");
  }
  printf("\n");
  printf("%d\n",count);

  return 0;
}

