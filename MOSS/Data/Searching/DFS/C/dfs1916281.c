#include<stdio.h>
#define WHITE 0
#define GRAY 1
#define BLUCK 2

void dfs();
void visit(int);

int matrix[200][200];
int color[200];
int sumvirtex;
int time;
int firstvirtextime[200];
int finalvirtextime[200];


int main(){

  int i,j,virtexnum,connectsum,connect;

  scanf("%d",&sumvirtex);

  for(i = 1; i<=sumvirtex; i++){

    scanf("%d",&virtexnum);
    scanf("%d",&connectsum);

    for(j = 1; j <= connectsum; j++){

      scanf("%d",&connect);

      matrix[i][connect] = matrix[i][connect] + 1;

    }
  }

  /* for(i = 1; i<= sumvirtex;i++){

    for(j = 1; j <= sumvirtex;j++){

      printf("%d",matrix[i][j]);

    }

    }*/

  dfs();

    for(i=1; i<= sumvirtex; i++){

    printf("%d %d %d\n",i,firstvirtextime[i],finalvirtextime[i]);

  }
  

  return 0;

}

void dfs(){

  int i;

  for(i = 1; i <= sumvirtex; i++){

    color[i] = WHITE;

  }

  time = 0;

  for(i =1 ; i <= sumvirtex; i++){

    if(color[i] == WHITE){

    visit(i);

    }

  }

  /*for(i = 1; i <= sumvirtex; i++){

    printf("%d %d %d\n",i,firstvirtextime[i],finalvirtextime[i]);

    }*/

}

void visit(int i){

  int j;

  color[i] = GRAY;

  firstvirtextime[i] = ++time;

  for(j = 1; j <= sumvirtex; j++){

    if(matrix[i][j] == 1 && color[j] == WHITE){

      visit(j);

    }

  }

  color[i] == BLUCK;

    finalvirtextime[i] = ++time;

}
