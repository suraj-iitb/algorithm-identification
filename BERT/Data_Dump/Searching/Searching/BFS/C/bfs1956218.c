#include<stdio.h>
#define WHITE 0
#define GRAY 1
#define BLUCK 2
#define INF 200000000
void bfs(int);
void visit(int);
void enqueue(int);
int  dequeue();
 
int matrix[200][200];
int color[200];
int d[300];
int sumvirtex;
int queue[100]; 
int head;
int tail;
 
int main(){
 
  int i,j,virtexnum,connectsum,connect;
 
  //printf("test");
  scanf("%d",&sumvirtex);
  // printf("test");
  for(i = 1; i<=sumvirtex; i++){
 
    scanf("%d",&virtexnum);
    scanf("%d",&connectsum);
 
    for(j = 1; j <= connectsum; j++){
 
      scanf("%d",&connect);
 
      matrix[i][connect] =  1;
      // printf("%d\n",connect);
    }
  }
 

  /* for(i = 1; i<= sumvirtex;i++){
 
    for(j = 1; j <= sumvirtex;j++){
 
      printf("%d",matrix[i][j]);
 
    }
 
    }*/
 
  // printf("test");
   bfs(1);
 
  /* for(i=1; i<= sumvirtex; i++){
 
    printf("%d %d %d\n",i,firstvirtextime[i],finalvirtextime[i]);
 
    }*/
   
  for(i = 1; i <= sumvirtex; i++){

    if(d[i] == INF){

      d[i] = -1;

    }

    printf("%d %d\n",i,d[i]);

  }
 
  return 0;
 
}
 
void bfs(int s){
 
  int i,j,u;
  int dequeuenum;

  // printf("test");
  for(i = 1; i <= sumvirtex; i++){
 
    color[i] = WHITE;
    d[i] = INF;
  }
 
  // printf("test");
  color[s] = GRAY;
 
  d[s] = 0;

  enqueue(s);

  while((u = dequeue()) != -1){

    // printf("%d\n",u);

    for(j = 1; j <= sumvirtex; j++){

      if(matrix[u][j] != 0 && color[j] == WHITE){

	color[j] = GRAY;

	d[j] = d[u] + 1; 

	enqueue(j);

	  }
    }

  }
    color[u] = BLUCK;
}

void enqueue(int key){

  queue[tail] = key;

  tail = tail + 1;
}

int  dequeue(){

  int value;

  if(head == tail){

    return -1;

  }
 
  else{ 

    value = queue[head];

    head = head + 1;

  }
 
 return value;

}


/* for(i =1 ; i <= sumvirtex; i++){
 
    if(color[i] == WHITE){
 
      visit(i);
 
    }
 
    }*/
 
  /*for(i = 1; i <= sumvirtex; i++){
 
    printf("%d %d %d\n",i,firstvirtextime[i],finalvirtextime[i]);
 
    }*/
 
/*}
 
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
 
}*/
