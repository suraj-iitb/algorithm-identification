#include<stdio.h>
#include<stdlib.h>
typedef struct list{
  int u, k, *v;
}T_list;
typedef struct graph{
  int d, f;
}T_graph;
int n;
T_list *lst;
T_graph *grp;
int que[100];
int p, q;
void bfs(int);
int main(){
  scanf("%d", &n);
  lst = (T_list *)malloc(sizeof(T_list) * n);
  grp = (T_graph *)malloc(sizeof(T_graph) * n);
  int i, j;
  for(i = n - 1; i >= 0; i--)
    grp[i].d = -1;
  for(i = 0; i < n; i++){
    scanf("%d %d", &lst[i].u, &lst[i].k);
    if(lst[i].k){
      lst[i].v = (int *)malloc(sizeof(int) * lst[i].k);
      for(j = 0; j < lst[i].k; j++){
    scanf("%d", &lst[i].v[j]);
  
      }
  
    }
  }
  grp[0].d = 0;
  p, q = 0;
  que[q] = 0;
  q++;
  for(p = 0; p < n; p++)
      bfs(que[p]);
  for(i = 0; i < n; i++){
    if(lst[i].k)
      free(lst[i].v);
    printf("%d %d\n", i + 1, grp[i].d);
  }
  free(grp), free(lst);
  return 0;
}
 
void bfs(int v){
  
  int i;
  for(i = 0; i < lst[v].k; i++){
    if(!(grp[lst[v].v[i] - 1].d + 1)){
      grp[lst[v].v[i] - 1].d = grp[v].d + 1;
      que[++q] = lst[v].v[i] - 1;
     
    }
  }
}
