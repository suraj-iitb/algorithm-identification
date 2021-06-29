#include <stdio.h>

int main()
{
  int N, data[100], i;
  int flag, c=0, x;

  scanf("%d",&N);
  for(i = 0 ; i < N ; i++)
    scanf("%d",&data[i]);

  flag = 1;
  while(flag == 1){
    flag = 0;
    for( i = N-1 ; i > 0 ; i--){
      if(data[i] < data[i-1]){
	x = data[i];
	data[i] = data[i-1];
	data[i-1] = x;
	flag = 1;
	c++;
      }
    }
  }
  i=0;
  while(1){
    printf("%d",data[i]); 
    if(i == N-1)break;
    printf(" ");
    i++;
  }
  printf("\n");
  printf("%d\n",c);

  return 0;
}
