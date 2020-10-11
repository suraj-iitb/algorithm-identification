#include <stdio.h>

int selectionSort();
int i,j;
int x[100];
int n;

int main(){
  int tem;
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&x[i]);
  }
  
  tem = selectionSort();

    for(i=0;i<n;i++){
      printf("%d",x[i]);
      if(i<n-1){
	printf(" ");
      }
    }
    printf("\n%d\n",tem);
    
    return 0;
  }
  int selectionSort(){
    int cnt = 0;
    int minj;
    int tem;
    for(i=0;i<n-1;i++){
      minj = i;

      for(j=i;j<n;j++){
	if(x[j] < x[minj]){
	  minj = j;
	}
      }
      if(x[i] != x[minj]){
      tem = x[i];
      x[i] = x[minj];
      x[minj] = tem;
      cnt++;
      }
    }
    return cnt;
  }
  




























