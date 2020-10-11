#include <stdio.h>
int count=0;
void sw(int *a,int *b){
  int t;
  t = *a;
  *a = *b;
  *b = t;
}

void B_sort(int array[],int s){
  int a,b;
  for(a=0;a<s-1;a++){
    for(b=s-1;b>=a+1;b--){
      if(array[b]<array[b-1]){
          sw(&array[b],&array[b-1]);
          count++;
        }
    }
  }
}
int main(){
  int s;
  int a[10000];
  int i;
  scanf("%d",&s);
  for(i=0;i<s;i++){
    scanf("%d",&a[i]);
  }
  B_sort(a,s);

  for(i=0;i<s-1;i++){
    printf("%d",a[i]);
    printf(" ");
  }
  printf("%d",a[s-1]);
  printf("\n");
  printf("%d\n",count);
  return 0;
}
