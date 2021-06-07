#include<stdio.h>

#define N 101


int MAX = (1<<21), fir = 0, time = 1, thi = 2, n, A[N][N], num[N], d[N], f[N], count;



void deps(int x){

  int i;

  num[x] = time;

  count++;

  d[x] = count;

  for ( i = 0; i < n; i++ )
    {

      if ( A[x][i] == 0 )
	{
	  continue;
	}
      
      if ( num[i] == fir )
	{

	  deps(i);

	}
    }

  num[x] = thi;

  f[x] = ++count;

}

void dfs(){

  int i, x;

  for ( i = 0; i < n; i++ )
    {
      num[i] = fir;
    }
  
  count = 0;

  for ( x = 0; x < n; x++ ){

    if ( num[x] == fir ) deps(x);

  }

  for ( i = 0; i < n; i++ ){

    printf("%d %d %d\n", i+1, d[i], f[i]);

  }

}

int main(){
  
  int x, y, z, i, j;

  scanf("%d", &n);

  for ( i = 0; i <n; i++ )
    {
      for ( j = 0; j <n; j++ )
	{
	  A[i][j] = 0;
	}
    }
  
  for ( i = 0; i < n; i++ )
    {
      scanf("%d %d", &x, &y);
     
      for ( j = 0; j < y; j++ )
	{
	  scanf("%d", &z);

	  A[x-1][z-1] = 1;
	}
    }
  
  dfs();

  return 0;
}
