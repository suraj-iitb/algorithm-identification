#include <stdio.h>
#include <stdlib.h>
#define MAX 2000000

void CountingSort(int *,int *,int);

int result[MAX+1];

int main(){
  int i,l,r,n,arr[MAX],count[10000+1];

  for(i=0;i<=10001;i++) count[i] = 0;
  scanf("%d",&n);
  if(n>MAX) exit(2);
  for(i=0;i<n;i++){
    scanf("%d",&arr[i]);
  }
  CountingSort(arr,count,n);
  for(i=1;i<n+1;i++){
    if(i>1) printf(" ");
    printf("%d",result[i]);
  }
  printf("\n");
  return 0;
}

void CountingSort(int arr[],int count[],int n){
  int i;
  for(i=0;i<n;i++){
    count[arr[i]]++;
  }
  for(i=1;i<=10001;i++){
    count[i] = count[i-1] + count[i];
  }
  for(i=n-1;i>=0;i--){
    result[count[arr[i]]]=arr[i];
    count[arr[i]]--;
  }
}

