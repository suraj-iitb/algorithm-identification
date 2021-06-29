#include <stdio.h>
#include <stdlib.h>
#define N 100

int SelectionSort(int,int *);

int main(){
  int a,*num,i;
  scanf("%d",&a); 
  num = (int*)malloc(a*sizeof(int));
  for(i = 0;i < a;i++){
    scanf("%d",&num[i]);
  }
  SelectionSort(a,num);
  free(num);
  return 0;
  }

int SelectionSort(int len,int *a){
  int i,j,min,tmp,cnt=0;

  for(i = 0;i < len - 1;i++){
    min = i;
    for(j = i + 1;j < len;j++){
      if(a[j] < a[min]){
	       min = j;
      }

    }

    if(min != i){
      tmp = a[i];
      a[i] = a[min];
      a[min] = tmp;
      cnt++;
    }
    printf("%d ",a[i]);
  }
  printf("%d",a[len-1]);
  printf("\n");
  printf("%d\n",cnt);
  return 0;
}
