#include<stdio.h>
int main(){
  int l[100];
  int i;
  int temp;
  int j;
  int number;
  int k;
  scanf("%d",&number);
  for(i=0;i<number;i++){
    scanf("%d",&l[i]);
  }
  for(i=0;i<number-1;i++){
    printf("%d ",l[i]);
  }
  printf("%d\n",l[number-1]);
  for(i=1;i<number;i++){
    temp=l[i];
    j=i-1;
    while(j>=0&&l[j]>temp){
      l[j+1]=l[j];
      j=j-1;
    }
      l[j+1]=temp;
    for(k=0;k<number-1;k++){
      printf("%d ",l[k]);
    }
    printf("%d\n",l[number-1]);
  }
  return 0;
}

