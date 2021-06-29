#include<stdio.h>
#define N 10000
#define M 500

int main(){

  int i, j, n, m, cnt = 0, array[N], srh_array[M];
  
  scanf("%d",&n);

  for(i = 0; i < n ; i++)scanf("%d",&array[i]);
  
  scanf("%d",&m);

  for(i = 0; i < m ; i++)scanf("%d",&srh_array[i]);
  
  for(i = 0; i < m; i++)
    {
      for(j = 0; j < n; j++)
	{
	  if(srh_array[i] == array[j])
	    {
	      cnt++;
	      break;
	    }
	}
    }
  printf("%d\n",cnt);
  
  return 0;
}

