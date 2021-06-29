#include <stdio.h>
#include <stdlib.h>

#define N 101
#define INF -1

typedef struct al { // adjacency list
  int        id;
  struct al* next_p;
} al_s;

typedef enum {
  WHITE,
  GRAY,
  BLACK,
} color_t;

// queue
int queue[N] = {NULL};
int first = 0;
int last  = 0;

int time_g = 0;

void chkList(al_s**, int);
int isEmpty();
void enq(int id);
int deq();
void setAdjs(al_s* g_p, int* adjs_p, color_t*);



int main(){
  int    n = 0, u = 0, k = 0 ,v = 0;
  al_s* g_p[N] = {0}; // 1-origin
  color_t color[N];   // 1-origin
  int d[N]={0};
  int i, j;
  int adjs[N] = {0};

  scanf("%d", &n);
  for ( i = 0; i < n; i++ ){
    scanf("%d%d", &u ,&k);
    al_s *node_p = g_p[u];
    for( j = 1 ; j <= k ; j++ ){
      scanf("%d" ,&v );
      al_s *aloc_p = (al_s*)malloc(sizeof(al_s));
      if( node_p == NULL ){
	node_p = aloc_p;
	g_p[u] = node_p;
      }else{
        node_p->next_p = aloc_p;
        node_p = node_p->next_p;
      }
      node_p->id = v;
      node_p->next_p = NULL;
    }
  }

  for( u=0 ; u<=n ; u++){
    color[u] = WHITE;
    d[u]     = INF;
  }
  color[1] = GRAY; // s is 1.
  d[1]     = 0;
  enq(1);
  
  while( isEmpty() != 0 ){
    u = deq();
    setAdjs(g_p[u] ,adjs ,color);
    for( i=0 ; adjs[i]!=0 ; i++ ){
      v = adjs[i];
      if( color[v] == WHITE ){
	color[v] = GRAY;
	d[v] = d[u] + 1;
	enq(v);
      }
    }
    color[u] = BLACK;
  }

  for( i=1; i<=n ; i++ ){
    printf("%d %d\n" ,i ,d[i] );
  }

  return 0; // Don't forget return 0  
}

int isEmpty(){
  return abs(first-last);
}

void enq(int id){
  queue[last] = id;
  last++; 
  if(last == N ){
    last = 0;
  }
}

int deq(){
  int ret;

  if(isEmpty()!=0){
    ret = queue[first];
    first++;
    return ret;
  }

  return NULL;
}

void setAdjs(al_s* g_p, int* adjs_p, color_t* clr_p){
  int i;
  al_s* nd_p = g_p;

  adjs_p[0] = 0;
  if(nd_p==NULL){ // the u node has no next node.
    return;
  }

  for(i=0 ; i < N ; i++){
    adjs_p[i] = nd_p->id;
    nd_p = nd_p->next_p;
    if( nd_p == NULL ){
      return;
    }
  }

  return;  
}


void chkList(al_s** g_pp, int n){ // for debug
  int i;

  for( i=1 ; i <= n ; i++){
    al_s* nd_p = g_pp[i];
    printf("%d: g_p[%d] = 0x%x\n" ,__LINE__ ,i ,g_pp[i] );
    while( nd_p != NULL ){
      printf("%d: nd_p         = 0x%x\n" ,__LINE__ ,nd_p );
      printf("%d: nd_p->id     = %d\n"   ,__LINE__ ,nd_p->id);
      printf("%d: nd_p->next_p = 0x%x\n" ,__LINE__ ,nd_p->next_p);
      nd_p = nd_p->next_p;
    }
    printf("\n");
  }

}
