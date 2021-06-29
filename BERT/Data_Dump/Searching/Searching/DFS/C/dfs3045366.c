#include<stdio.h>
#include<stdlib.h>

int S[500];
int top;

int **mat;
int n;
int tm=0;
int *disc, *fin;

void adjmatrix();
void push(int);
int pop();
void dsearch();

int main(){
  int i,j;

  adjmatrix();

  disc = (int *)malloc(n * sizeof(int));
  fin = (int *)malloc(n * sizeof(int));

  for(i=0; i<n; i++){
    disc[i] = 0;
    fin[i] = 0;
  }
  
  push(1);
  tm++;
  disc[0] = tm;


  while(tm != n*2){
    for(i=0; i<n; i++){
      if(disc[i]==0){
	push(i+1);
	tm++;
	disc[i] = tm;
	dsearch();
      }
    }
  }
  
  for(i=0; i<n; i++)
    printf("%d %d %d\n",i+1 ,disc[i] ,fin[i]);

  for(i=0; i<n; i++)
    free(mat[i]);
  free(mat);
  
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

void push(int x){
  S[++top] = x;
}

int pop(){
  return S[top--];
}

void dsearch(){
  int j;
  
  while(top!=0){
    for(j=0; j<n; j++){
      if(mat[S[top]-1][j]==1 && disc[j]==0){
	tm++;
	disc[j] = tm;
	push(j+1);
	break;
      }
    }

    if(j == n){
      tm++;
      fin[S[top]-1] = tm;
      pop();
    }
  }
}

