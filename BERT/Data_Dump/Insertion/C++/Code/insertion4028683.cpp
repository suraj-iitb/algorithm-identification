#include<stdio.h>

#define N 100

int main(int argc, char *argv[]){
  int i,j,tmp,n,arr[N];
  // read the number of elements and the elements
  scanf("%d",&n);
  for(i = 0; i < n; i++){
    scanf("%d",&arr[i]);
  }

  // sorting
  for(i = 0; i < n; i++){
    tmp = arr[i];
    j = i - 1;
    while(j >= 0 && arr[j] > tmp){
      arr[j+1] = arr[j];
      j--;
    }
    arr[j+1] = tmp;
    // output the sorted array
    for(j = 0; j < n; j++){
    printf("%d",arr[j]);
    if(j == n - 1) break;
    printf(" ");
  }
  printf("\n");
  
  }
}

