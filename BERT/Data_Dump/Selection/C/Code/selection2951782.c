#include <stdio.h>
#include <stdlib.h>

int sort(int *x, int n);
void ShowData(int *x, int n);

int main() {

  int *p;
  int i;
  int n;
  int count;

  scanf("%d",&n);
  
  p = (int *)malloc(n * sizeof(int)); //メモリ領域の確保

  for (i=0; i<n; i++)
    scanf("%d", &p[i]);

  count = sort(p,n);
  ShowData(p,n);
  printf("%d\n",count);
  
  return 0;
}

int sort(int *x, int n) {

  int i,j;
  int min;
  int tmp;
  int count = 0;

  for(i=0; i<n-1; i++){
    min = i;           //小さい値の保持
    
    for(j=i+1; j<n; j++){
      if(x[j] < x[min]){ 
	min = j;     //小さい値の更新
      }
    }
    /*sort*/
    if(x[i] > x[min]){
      tmp = x[i];
      x[i] = x[min];
      x[min] = tmp;
      count++;
    }
  }
  return count;
}

void ShowData(int *x, int n){

  int i;

  for(i=0; i<n; i++){
    if(i!=n-1) printf("%d ",x[i]);
    else printf("%d",x[i]);
  }

  printf("\n");
}

