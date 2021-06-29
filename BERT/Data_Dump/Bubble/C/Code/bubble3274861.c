#include <stdio.h>

int main(){
  int i,j,flag;
  int n,a;
  int count = 0;

  scanf("%d",&n);
  int data[n];
  for(i = 0;i < n;i++){
    scanf("%d",&a);
    data[i] = a;
  }

  for(i = 0;i < n;i++){
    int key;
    flag = 1;
    while(flag){
      flag = 0;
      for(j = n-1;j > 0;j--) {
        if(data[j] < data[j-1]){
	  key = data[j-1];
          data[j-1] = data[j];
          data[j] = key;
	  flag = 1;
	  count++;
	}
      }
    }
    for(i = 0;i < n;i++){
    printf("%d",data[i]);
    if(i==n-1) break;
    printf(" ");
    }
  printf("\n");
  printf("%d\n",count);
  }

  return 0;
}

