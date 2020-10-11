#include<stdio.h>

int main(){

  int count[10000];
  int i,j,a_num;
  unsigned short *a,*b;


  for(i = 0; i < 10000; i++){
    count[i] = 0;
  }

  scanf("%d",&a_num);
  a = malloc(sizeof(short)*a_num+1);
  b = malloc(sizeof(short)*a_num+1);

  for(i = 0; i < a_num; i++){
    scanf("%hu",&a[i+1]);
  }

  for(i = 0; i < a_num; i++){
    count[a[i+1]]++;
  }


  for(i = 1; i <= 10000; i++){
    count[i] = count[i]+count[i-1];
  }

  for(i = a_num; i > 0;i--){
    b[count[a[i]]] = a[i];
    count[a[i]]--;
  }

  for(i = 1; i < a_num; i++){
    printf("%d ",b[i]);
  }
  printf("%d\n",b[i]);

  return 0;
}
