#include <stdio.h>

int main()
{
  int i, j, length, keydata, data[100]; 

  //入力データの格納
  scanf("%d",&length);
  
  for(i = 0; i < length; i++) {
    scanf("%d",&data[i]);
  }

  //ソート前の出力
  for(i = 0; i < length; i++) {
    printf("%d",data[i]);
    if(i != length-1) printf(" ");
  }
  printf("\n");

  //ソートの実行とソート毎の出力
  for(i = 1; i <= length-1; i++) {
    keydata = data[i];
    j = i - 1;
    while(j >= 0 && data[j] > keydata) {
      data[j+1] = data[j];
      j--;
    }
    data[j+1] = keydata;

    for(j = 0; j < length; j++) {
      printf("%d",data[j]);
      if(j != length-1) printf(" ");
    }
    printf("\n");
  }

  return 0;
}



