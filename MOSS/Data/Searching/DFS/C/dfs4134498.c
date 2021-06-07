#include <stdio.h>

#define MAX 100
#define WHITE 0
#define GRAY 1
#define BLACK 2

int n,M[MAX][MAX],col[MAX],a[MAX],b[MAX],c;


void dfs_v(int l)
{
  int m;
  col[l]=GRAY;
  a[l]=++c;
  for( m=0 ; m<n ; m++ ){
    if( M[l][m]==0 )
      continue;
    if( col[m]==WHITE ){
      dfs_v(m);
    }
  }
  col[l]=BLACK;
  b[l]=++c;
}

void dfs(){
  int l;
  for( l=0 ; l<n ; l++ )
    col[l]=WHITE;
  c=0;

  for( l=0 ; l<n ; l++ ){
    if( col[l]==WHITE )
      dfs_v(l);
  }
  for( l=0 ; l<n ; l++ ){
    printf("%d %d %d\n",l+1,a[l],b[l]);
  }
}

int main()
{
  int l,m,k,i,j;

  scanf("%d",&n);

  for( i=0 ; i<n ; i++ ){
    for( j=0 ; j<n ; j++ )
      M[i][j]=0;
  }

  for( i=0 ; i<n ; i++ ){
    scanf("%d%d",&l,&k);
    l--;
    for( j=0 ; j<k ; j++ ){
      scanf("%d",&m);
      m--;
      M[l][m]=1;
    }
  }

  dfs();

  return 0;
  
}
  
			 
	

