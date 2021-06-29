#include<stdio.h>

int main(){
  int length1, length2, count=0, i, j;
  int array1[10000], array2[500];

  scanf("%d",&length1);
  for(i=0; i<=length1-1; i++){
    scanf("%d",&array1[i]);
  }

  scanf("%d",&length2);
  for(i=0; i<=length2-1; i++){
    scanf("%d",&array2[i]);
  }

  /* リニアサーチ開始 */

  for(i=0; i<=length2-1; i++){
    for(j=0; j<=length1-1; j++){
      if(array2[i]==array1[j]){
	count++;
	break;
      }
    }
  }

  printf("%d\n",count);

  return 0;
}

    

