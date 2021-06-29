#include <stdio.h>
int main(){

  int  arr[100], n,i,j,temp, mini, count=0;

  scanf("%d", &n);

  for(i=0; i<n; i++){
    scanf("%d", &arr[i]);
  }
  for(i=0; i<n-1; i++){
    mini=i+1;
    for(j=i+1; j<n; j++){
      if(arr[j]<arr[mini]){
	mini=j;
      }
    }
    if(arr[mini]<arr[i]){
      temp=arr[i];
      arr[i]=arr[mini];
      arr[mini]=temp;
      count++;
    }
  }
  for(i=0;i<n;i++){
    printf("%d",arr[i]);
    if(i<n-1){
      printf(" ");
    }
  }
  printf("\n");
  printf("%d\n", count);
  return 0;
}
