#include <stdio.h>

void selectionSort(int *,int);

int main(){
   int a[100],n,i;

  scanf("%d",&n);
  if(n < 1 || n > 100)return 0;
  
  for(i = 0; i < n; i++){
  scanf("%d",&a[i]);
  
  if(a[i] < 0 || a[i] > 100)return 0;
  }

  selectionSort(a,n);

  return 0;
}

void selectionSort(int a[], int n){
  int i,min,j,b,num = 0;

  for(i = 0;i < n-1; i++){
    min = i;
   for(j = i;j < n; j++){
    if(a[j] < a[min]){
      min = j;
     }
    }
   if(a[i] > a[min]){
    b = a[i];
      a[i] = a[min];
      a[min] = b;
      num++;
   }
  }

  for(j = 0; j < n; j++){
  printf("%d",a[j]);

  if(j != n-1)printf(" ");
  else printf("\n");
  }
  
  printf("%d\n",num);
  
}

