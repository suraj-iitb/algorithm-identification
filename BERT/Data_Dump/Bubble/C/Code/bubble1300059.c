#include <stdio.h>

int main(void)
{
  int item[100];
  int a, b, t;
  int count,x=0;
  scanf("%d",&count);
  for(a = 0; a < count; a++){
    scanf("%d", &item[a]);
  }
  
  for(a = 1; a < count; a++){
   for(b = count - 1; b >= a; b--){
     if(item[b] < item[b-1]){
       t = item[b];
       item[b] = item[b-1];
       item[b-1] = t;
       x++;
     }
   }
  }
  
  for(a = 0; a < count; a++){
    if(a == count -1)printf("%d\n", item[a]);
    else printf("%d ", item[a]);
  }
  printf("%d\n",x);
  return 0;
}
