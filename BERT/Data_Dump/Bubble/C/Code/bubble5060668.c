#include<stdio.h>
#include<stdlib.h>

int main(){
  int size, count=0, key, i, j, flag; /* それぞれ数列の長さ、交換回数、交換する要素を格納する
                               後半2つはループに用いる */
  int array[100]; /* ソート対象の配列宣言 */

  scanf("%d",&size);
  if(size<1 || size>100) exit(1);

  for(i=0; i <= size-1; i++){
    scanf("%d",&array[i]);
    if(array[i]<0 || array[i]>100) exit(1);
  }

  /* ソート開始 */

  flag = 1;
  i = 0;
  while(flag){
    flag = 0;
    for(j=size-1; j >= i+1; j--){
      if(array[j] < array[j-1]){
	count++;
	key = array[j];
	array[j] = array[j-1];
	array[j-1] = key;
	flag = 1;
     }
    }
    i++;
   }

  for(i=0; i <= size-1; i++){
    printf("%d",array[i]);
    if(i != size-1) printf(" ");
  }

  printf("\n%d\n",count);

  return 0;
}
  

