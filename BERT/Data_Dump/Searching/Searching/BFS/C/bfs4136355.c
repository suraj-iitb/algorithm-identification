#include <stdio.h>
#include <stdlib.h>
#define LENGTH 105
void bfs(int, int);
void enqueue(int);         /* use queue*/
int  dequeue(void);
int array[100][100],dis[100],queue[LENGTH],head=0,tail=0;
int main(){
  int num,i,j,id,nextnum,next;
  scanf("%d",&num);
  for(i=0;i<num;i++){
    for(j=0;j<num;j++){
      array[i][j]=0;
    }
  }
  for(i=0;i<num;i++){
    scanf("%d %d",&id,&nextnum);
    for(j=0;j<nextnum;j++){
     
      scanf("%d",&next);
      array[id-1][next-1]=1;
    }
  }
  bfs(0,num);
  for(i=0;i<num;i++){
    printf("%d %d\n",i+1,dis[i]);
  }
  return 0;
}
void bfs(int val,int num){
  int i,res;
  enqueue(val);
  for(i=0;i<num;i++) dis[i]=-1;
  dis[val]=0;
  while(1){
    res=dequeue();
    if(res==-1) break;
    for(i=0;i<num;i++){
      if(array[res][i]==0) continue;
      if(dis[i]!=-1) continue;
      dis[i]=dis[res]+1;
      enqueue(i);
    }
  }
  
}

void enqueue (int data){
  int next;
  next=(tail+1)%LENGTH;
  
  if(next==head) exit(2);
  queue[tail]=data;
  tail=next;
}

int  dequeue(){
  int data;
  if(head==tail) return -1;
  data=queue[head];
  head=(head+1)%LENGTH;
  return data;
}


  

