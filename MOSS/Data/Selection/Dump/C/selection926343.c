#include <stdio.h>

#define N 100

int main(){
  int i,j,mini,n,temp,count=0,array[N];

  scanf("%d",&n);
  for(i=0; i<n;i++){
    scanf("%d",&array[i]);
  }

  for(i=0; i<n; i++){
    mini = i;
    for(j=i; j<n; j++){
      if(array[j]<array[mini]) mini = j;
    }
    if(i != mini) count++;
    temp = array[i];
    array[i] = array[mini];
    array[mini] = temp;
  }
  
  for(i=0; i<n; i++){
    if(i>0) printf(" ");
    printf("%d",array[i]);
  }
  printf("\n%d\n",count);
  
  return 0;
}
