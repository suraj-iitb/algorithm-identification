#include<stdio.h>

#define INF -1
#define WHITE 0
#define GRAY 1
#define BLACK 2

int A[1000][1000],d[1000],color[1000],Q[1000],top=1,tail=1,n,v,u;

void bfs(int);

int main(){

  int i,j,k;

  // printf("wa-i1\n");

  scanf("%d",&n);

  //printf("wa-i2\n");

  for(i=1;i<=n;i++){

    A[i][i]=0;

  }
  

  for(i=1;i<=n;i++){
  
    scanf("%d%d",&u,&k);

    //printf("wa-i3\n");
    
    for(j=0;j<k;j++){

      scanf("%d",&v);
      
      A[u][v]=1;

    }
  }

  // for(i=1;i<=n;i++){
  // for(j=1;j<=n;j++){

  //  printf("%d ",A[i][j]);

  //}
  //printf("\n");

  //}

  

 

    // printf("wa-i5\n");
		
    bfs(1);


    
  

  // printf("wa-i6\n");
  
  for(i=1;i<=n;i++){

    printf("%d %d\n",i,d[i]);

  }

  return 0;
}

void bfs(int s){

  int i,u1;

  // printf("wa-i6\n");

  for(i=1;i<=n;i++){

    color[i] = WHITE;
    d[i] = INF;
    
  }

  //printf("wa-i7\n");

  // printf("s: %d\n",s);
  
  color[s] = GRAY;
  d[s] = 0;

  //printf("wa-i8\n");
  
  for(i=1;i<=n;i++){

    Q[i]=INF;
  }

  //printf("wa-i9\n");
  
  tail++;
  Q[tail-1]=s;

  while(tail != top){

    //printf("wa-i10\n");
    top++;
    u1=Q[top-1];

    //printf("Q[top-1]: %d\n",Q[top-1]);

    for(i=1;i<=n;i++){

      //printf("wa-i11\n");

      if(A[u1][i]==1 && color[i]==WHITE){

	//printf("<wa-iwa-iwai>u1:%d,i: %d\n",u1,i);
	color[i]=GRAY;
	d[i]= d[u1] + 1;

	

	//	printf("d[%d]=%d\n",i,d[i]);

	tail++;
	Q[tail-1]=i;
      }
      
    }

    color[u1] = BLACK;
  }

}
