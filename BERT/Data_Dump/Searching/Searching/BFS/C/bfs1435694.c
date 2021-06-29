#include<stdio.h>
#include<stdlib.h>
 
#define N 101
#define BLACK 200
#define WHITE 201
#define GRAY 202
void BFS(int);
void Enqueue(int);
int Dequeue();
 
int t =0,num = 0,head =0,tail =0,save=0,change=1000000;
int d[N],color[N],num4[N][N];
int Q[N];
 
int main(){
  int i,j,num2,num3,num5,flag;
  scanf("%d",&num);
  
  for(i=1;i<=num;i++){
    for(j=1;j<=num;j++){
      num4[i][j] = 0;
    }
  }
  
   for(i=1;i<=num;i++){
     scanf("%d",&num5);
     save = num5;
     if(save < change) change = save;
 
     scanf("%d",&num2);
     if(num2 == 0)continue; 
     else{
       for(j=0;j<num2;j++){
     scanf("%d",&num3);
     num4[i][num3] = 1; 
       }
     }   
   }
 
 
   
     BFS(change);  //i=min ????
    
 
 
   for(i=1;i<=num;i++){
     if(d[i]==1000000000){
       d[i] = -1;
}
 
     printf("%d %d\n",i,d[i]);
     }
       
    
   return 0;
}
 
 
void BFS(int s){
  int i,v,Q;
  for(i=1;i<=num;i++){
    color[i]=WHITE;
    d[i]=1000000000;
  }
  color[s] =GRAY;
  d[s] = 0;
   
  Enqueue(s);
   
  while(head !=tail){
    i = Dequeue();
    for(v=1;v<=num;v++){
 
      if(color[v] == WHITE && num4[i][v] == 1){
 
    color[v] = GRAY;
    d[v] =d[i] + 1;
        Enqueue(v);
      }
    }
  
    color[i] = BLACK;
 }
   
}
 
void Enqueue(int x){
 
  Q[tail] = x;
  tail++;
 
}
 
int Dequeue(void){
 
  int x;
 
  x = Q[head];
  head++;
 
  return x;
}
