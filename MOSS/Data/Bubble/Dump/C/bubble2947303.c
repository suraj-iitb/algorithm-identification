#include <stdio.h>
#include <stdlib.h>

int BubSort(int *x, int n);
void ShowData(int *x, int n);  

int main() {

  int *p;
  int i;
  int n;
  int num;

  scanf("%d",&n);
  
  p = (int *)malloc(n * sizeof(int)); //メモリ領域の確保

  for (i=0; i<n; i++)
    scanf("%d", &p[i]);

  num = BubSort(p,n);
  ShowData(p,n);
  printf("%d\n",num);

  return 0;
}

int BubSort(int *x, int n){

  int i,j;
  int tmp;
  int num = 0;

  for(i=0; i<n-1; i++){
    for(j=n-1; j>i; j--){
      if(x[j-1] > x[j]){
	tmp = x[j];
	x[j] = x[j-1];
	x[j-1] = tmp;
	num++;	
      }
    }
  }
  return num;
}

void ShowData(int *x, int n){

  int i;

  for(i=0; i<n; i++){
    if(i!=n-1) printf("%d ",x[i]);
    else printf("%d",x[i]);
  }

  printf("\n");
}

