#include<stdio.h>
#define MAX 101
int datanum;
void print(int a[]){
  int i;
  for(i=0;i<datanum;i++){
    if(i)printf(" ");
    printf("%d",a[i]);
  }
  printf("\n");
}








int main(){
  int v,i,j;
  int a[MAX];
  scanf("%d",&datanum);
  for(i=0;i<datanum;i++){
    scanf("%d",&a[i]);
  }
  print(a);
  for(i=1;i<datanum;i++){
    v = a[i];
    j = i-1;
    while(j >= 0 && a[j] > v){
      a[j+1] = a[j];
      j--;
    }
    a[j+1] = v;
    print(a);
  }
  
  return 0;
}

