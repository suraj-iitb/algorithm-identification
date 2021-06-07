#include <stdio.h>

int linerSearch(int ,int* ,int);

int main()
{
  int count = 0;
  int a,b,c,i;
  int t[10010];

  scanf("%d",&a);
  
  for(i = 0;i < a;i++ ){
    scanf("%d",&t[i]);
  }

  scanf("%d",&b);
  
  for(i = 0; i < b; i++){
    scanf("%d",&c);
    count += linerSearch(a,t,c);
  }

  printf("%d\n",count);
  
  return 0;
}

int linerSearch(int x, int *y, int z)
{
  int i;
  
  for(i = 0; i < x; i ++){
    if(y[i] == z) return 1;
  }
  
  return 0;
}

