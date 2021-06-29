#include<stdio.h>
#define N 100

void trace(int num[],int n){
  int i;

  for(i = 1;i <= n;i++){
    if(i > 1) printf(" ");
    printf("%d",num[i]);
  }
  
  printf("\n");
}

int main(){
  int i,j,n,num[N + 1],a;

  scanf("%d",&n);
  
  for(i = 1;i <= n;i++) scanf("%d",&num[i]);

  trace(num,n);

  for(i = 2;i <= n;i++){
    a = num[i];
    j = i - 1;
    while(j > 0 && num[j] > a){
      num[j + 1] = num[j];
      j--;
    }
    num[j + 1] = a;

    trace(num,n);
  }

  return 0;
}


