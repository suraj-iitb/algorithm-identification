#include <stdio.h>
int BinarySearch (int* ,int ,int);
int main()
{
  int i,a=0,same=0;
  int S[100000],T[50000],s_num,t_num;
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
      same+=BinarySearch(S,T[i],s_num);
      // printf("aaaaaaaaa\n");
    }
  printf("%d\n",same);
  return 0;
}

int BinarySearch(int* S,int key,int s_num)
{
  int i=0,left=0,right=s_num,mid=0;
  while(left < right)
    {
      mid = (left+right)/2;
      if(key == S[mid]) return 1;
      else if (key > S[mid]) left = mid +1;
      else right = mid;
    }
  return 0;
}
