#include<stdio.h>

int bubbleSort(int [], int n);

int main(){
  int n,a[100],i,c;
  scanf("%d",&n);
  
  for(i = 0; i < n; i++){
    scanf("%d",&a[i]);
    }

  c = bubbleSort(a, n);

  for(i = 0; i < n; i++){
    if(i != n-1) printf("%d ",a[i]);
    else printf("%d",a[i]);
  }
  printf("\n");
  printf("%d\n",c);

  return 0;
}

int bubbleSort(int a[], int n){
  int flag = 1,j,tmp,c=0;

  while(flag){
    flag = 0;
    for(j = n-1; j >= 1; j--){
      if(a[j] < a[j-1]){
	tmp = a[j];
	a[j] = a[j-1];
	a[j-1] = tmp;
	flag = 1;
	c++;
      }
    }
  }
  return c;
}

