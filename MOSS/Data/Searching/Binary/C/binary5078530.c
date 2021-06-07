#include<stdio.h>

int main(){
  int length1, length2, count=0, i;
  int left, right, mid;
  int array1[100000], array2[50000];

  scanf("%d",&length1);
  for(i=0; i<=length1-1; i++){
    scanf("%d",&array1[i]);
  }

  scanf("%d",&length2);
  for(i=0; i<=length2-1; i++){
    scanf("%d",&array2[i]);
  }

  /* サーチ開始 */

  for(i=0; i<=length2-1; i++){
    left=0;
    right=length1;
    while(left<right){
      mid=(left+right)/2;
      if(array1[mid]==array2[i]){
	count++;
	break;
      }
      else if(array2[i]<array1[mid]) right=mid;
      else left=mid+1;
    }
  }

  printf("%d\n",count);

  return 0;
}

    
    
    

