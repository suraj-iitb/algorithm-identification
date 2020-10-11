#include <stdio.h>
#define MAX 100
void insertionSort(int *,int);
int main(){
  int a[MAX];
  int n,i;
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&a[i]);
  }
  insertionSort(a,n);

  
  return 0;
}


void insertionSort(int *a,int n){
  int i,j,s,key=0;
  for(i=0;i<n;i++){
 
    
    key = a[i];
    j = i-1;
    while(j >= 0 && a[j] > key){
      a[j+1]=a[j];
      j--;
      a[j+1] = key;
    }
    for(s=0;s<n;s++){
      if(s>0)printf(" ");
      printf("%d",a[s]);
    }
    printf("\n");
    
  }
}

