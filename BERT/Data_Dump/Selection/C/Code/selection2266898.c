#include <stdio.h>

#define N 100

int main(){

  int i;
  int j;
  int min;
  int n;
  int tmp;
  int count=0;
  int data[N];

  scanf("%d",&n);

  for(i=0;i<n;i++){
    scanf("%d",&data[i]);
  }

  for(i=0;i<n-1;i++){
        min = i;
    for(j=i+1;j<n;j++){
      if( data[j] < data[min]){
	min = j;
      }
    }
    if(min != i){
	tmp = data[i];
	data[i] = data[min];
	data[min] = tmp;
	count++;
   }
  }
  for(i=0;i<n-1;i++){
    printf("%d ",data[i]);
  }
    printf("%d\n",data[i]);
    printf("%d\n",count);

    return 0;
}
