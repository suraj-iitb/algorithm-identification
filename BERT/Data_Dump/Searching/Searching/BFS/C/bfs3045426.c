#include<stdio.h>
#include<stdlib.h>

int Q[500];
int head,tail;

int **mat;
int n;

void adjmatrix();
void enq(int);
int deq();

int main(){
  int i,j;
  int *dist;
  int *flg;

  adjmatrix();
  dist = (int *)malloc(n * sizeof(int));
  flg = (int *)malloc(n * sizeof(int));

  for(i=0; i<n; i++){
    dist[i] = -1;
    flg[i] = 0;
  }

  enq(1);
  dist[0] = 0;
  flg[0]++;
  
  while(head != tail){
    for(j=0; j<n; j++){
      if(mat[Q[head]-1][j]==1 && flg[j]==0){
	enq(j+1);
	dist[j] = dist[Q[head]-1] + 1;
	flg[j]++;
      }
    }

    deq();
  }

  for(i=0; i<n; i++)
    printf("%d %d\n",i+1 ,dist[i]);

  for(i=0; i<n; i++)
    free(mat[i]);
  free(mat);
  free(dist);
  free(flg);
  return 0;
}

void adjmatrix(){
  int u, k;
  int *v;
  int i, j;

  scanf("%d",&n);

  mat = (int **)malloc(n * sizeof(int *));
   
  for(i=0; i<n; i++){
    mat[i] = (int *)malloc(n * sizeof(int));
    for(j=0; j<n; j++)
      mat[i][j] = 0;
  }

  for(i=0; i<n; i++){
    scanf("%d%d",&u ,&k);

    v = (int *)malloc(k * sizeof(int));

    for(j=0; j<k; j++){
      scanf("%d",&v[j]);
      mat[u-1][v[j]-1] = 1;
    }

    free(v);
  }
}

void enq(int x){
  Q[tail++] = x;
}

int deq(){
  return Q[head++];
}

