#include<stdio.h>
 

int bubble_sort(int* a, int b){
  int i,j, c = 0;
  for(i = 0; i < b; i++)
    for(j = b-1; j >= i+1; j--)
      if(a[j] < a[j-1]){
    int tmp = a[j];
    a[j] = a[j-1];
    a[j-1] = tmp;
    c++;
      }
  print(a,b);
  return c;
}

void print(int* a, int b){
  int i;
  for(i = 0; i < b; i++){
    if(i) printf(" ");
    printf("%d",a[i]);
  }
  printf("\n");
}


 
int main(){
  int i,b,dat[100];
  scanf("%d",&b);
  for(i = 0; i < b; i++) scanf("%d",&dat[i]);
  printf("%d\n",bubble_sort(dat,b));
  return 0;
}
 



 
 
