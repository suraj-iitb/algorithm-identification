#include<stdio.h>
#include<stdlib.h>
#define N 100

int main(){

  int a[N];
  int i,j,minj,len,count=0,c;

  scanf("%d\n",&len);
  if(len>N)exit(8);
  for(i = 0; i < len; i++){
    scanf("%d",&a[i]);
  }

  for(i =0; i < len; i++){
    minj = i;
    for(j = i; j < len; j++){
      if(a[j] < a[minj]) minj = j;
    }
 
    if(minj != i)count++;

    c = a[i];
    a[i] = a[minj];
    a[minj] = c;

  }

  for(i = 0; i < len; i++){
    if(i == len-1)printf("%d",a[i]);
    else{
      printf("%d",a[i]);
      printf(" ");
    }
  }
  printf("\n");
  printf("%d\n",count);

  return 0;
}
