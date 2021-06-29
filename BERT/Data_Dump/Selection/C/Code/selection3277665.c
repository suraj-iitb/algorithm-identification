#include<stdio.h>

int selectionSort(int [], int);

int main(){
  int n,a[100],i,c;

  scanf("%d",&n);
  for(i = 0; i < n; i++) scanf("%d",&a[i]);

  c = selectionSort(a, n);

  for(i = 0; i < n; i++){
    if(i == n-1 )printf("%d\n",a[i]);
    else printf("%d ",a[i]); 
  }
  printf("%d\n",c);
  
  return 0;
}

int selectionSort(int a[], int n){
  int i,j,minj,temp,c=0;

  for(i = 0; i <= n-1; i++){
    minj = i;
    for(j = i; j <= n-1; j++){
      if(a[j] < a[minj]) minj = j;
    }
    if(i != minj) c++;
    temp = a[i];
    a[i] = a[minj];
    a[minj] = temp;
  }
  return c;
}

