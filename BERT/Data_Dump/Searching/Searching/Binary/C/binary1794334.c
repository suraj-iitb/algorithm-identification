#include<stdio.h>
#define N 100000

int main (){
int i,a,array1[N],b,array2[N];
int count = 0 , left = 0, right,mid;
   scanf("%d",&a);
   for(i = 0 ; i < a ; i++){
    scanf("%d",&array1[i]);
  }
  scanf("%d",&b);
  for(i = 0 ; i < b ; i++){
    scanf("%d",&array2[i]);
  }
  for(i = 0 ; i < b ; i++){
    left = 0;
    right = a;

    while(left < right){
      mid=(left+ right) / 2;

      if(array1[mid] == array2[i]){
    count++;
    break;
      }

      else if(array2[i] < array1[mid]){
    right = mid;
      }

      else {
    left = (mid+1);
      }

    }

  }
  printf("%d\n",count);
  return 0;
}
