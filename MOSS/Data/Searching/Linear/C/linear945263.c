#include <stdio.h>
int linearSearch (int* ,int ,int);
int main()
{
  int i,a=0,same=0;
  int S[10000],T[500],s_num,t_num;
  scanf("%d",&s_num);
  for(i=0;i<s_num;i++)
    { 
      scanf("%d",&S[i]);
      // printf("S %d \n",S[i]);
    }
  scanf("%d",&t_num);
  for(i=0;i<t_num;i++)
    {
      scanf("%d",&T[i]);
      // printf("T %d \n",T[i]);
    }

  for(i=0;i<t_num;i++)
    {
      same+=linearSearch(S,T[i],s_num);
      // printf("aaaaaaaaa\n");
    }
  printf("%d\n",same);
  return 0;
}

int linearSearch(int* S,int key,int s_num)
{
  int i=0;
  for(i=0;i<s_num;i++)
    {
      // printf("bbbbbbbbbb\n");
      if(S[i]==key) return 1;
    }
  return 0;
}
