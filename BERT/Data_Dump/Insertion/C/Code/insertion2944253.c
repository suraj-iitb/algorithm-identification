#include <stdio.h>
#include <string.h>
#define N 100
void insertionSort(int*,int);
int main (){
  int A[N],a,b,i;
  
  scanf("%d",&b);
  for(i=0;i<b;i++){
    scanf("%d",&A[i]);
  }
  insertionSort(A,b);

  return 0;
}

void insertionSort(int *a,int b){
  int i,j,k,v;
  for(k=0;k<b;k++){
      printf("%d",*(a+k));
      if(k!=b-1) printf(" ");
      else printf("\n");
    }
  for(i=1;i<b;i++){
    v = *(a+i);
    j=i-1;
    while(j>=0 && *(a+j)>v){
      *(a+j+1) = *(a+j);
      j--;
      *(a+j+1) = v;
    }
    for(k=0;k<b;k++){
      printf("%d",*(a+k));
      if(k!=b-1) printf(" ");
      else printf("\n");
    }
  }
}

