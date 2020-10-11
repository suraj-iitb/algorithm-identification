#include <stdio.h>

#define N 100

int main(void){

  int i,j,n,mini,temp,c=0;
  int arr[N];
  
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&arr[i]);
  }

  for(i=0;i<n-1;i++){
    mini = i;
    for(j=i+1;j<n;j++){
      if(arr[j] < arr[mini]){
	mini = j;
      }
    }
    if(i !=mini){
      temp = arr[i];
      arr[i] = arr[mini];
      arr[mini] = temp;
      c++;
    }
  }

  for(i=0;i<n;i++){
    printf("%d",arr[i]);
    if(i != n-1) printf(" ");
  }

  printf("\n%d\n",c);

  return 0;

}

