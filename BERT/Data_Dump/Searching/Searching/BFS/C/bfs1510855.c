#include <stdio.h>
#include <stdlib.h>
#define MAX 101
#define WHITE 0
#define GRAY 1
#define BLACK 2






int queue[MAX], color[MAX], M[MAX][MAX], d[MAX];
int end, top;

void enqueue(int n){


 if(end == MAX)
   end = 0;

   queue[end] = n;
   end++;

}

int dequeue(){
int retval;

  if(top == MAX)
   top = 0;


  retval = queue[top];

  top++;

  return retval;
}

void bfs(int s, int f){
int u, count = 0;
 enqueue(s);

  while(end != top){
   u = dequeue();
   color[u] = BLACK;
    while(M[u][count] != 0){
     if(color[M[u][count]] == WHITE){
      enqueue(M[u][count]);
      color[M[u][count]] = GRAY;
      d[M[u][count]] = d[u] + 1;
     }
     count += 1;
 }

    count = 0;
  }

}

int main(){
int count = 0, n, count2, id, num;
 scanf("%d", &n);
 for(count; count < n; count++){
  scanf("%d %d", &id, &num);
   for(count2 = 0; count2 < num; count2++){
     scanf("%d", &M[id][count2]);
   }

 }


 bfs(1, 0);

 for(count2 = 0; count2 < n; count2++){
   if(d[count2 + 1] != 0 || count2 == 0)
   printf("%d %d\n", count2+1, d[count2+1]);
   else
   printf("%d %d\n", count2+1, -1);

 }


 return 0;
}
