#include <stdio.h>
void dfsv(int, int);
int array[100][100],col[100],found[100],fin[100],time;
int main(){
  int num,i,j,id,nextnum,next;
  scanf("%d",&num);
  for(i=0;i<num;i++){
    for(j=0;j<num;j++){
      array[i][j]=0;
    }
  }
  for(i=0;i<num;i++){
    scanf("%d%d",&id,&nextnum);
    for(j=0;j<nextnum;j++){
      scanf("%d",&next);
      array[id-1][next-1]=1;
    }
  }
  for(i=0;i<num;i++) col[i]=0;
  time=0;
  for(i=0;i<num;i++){
    if(col[i]==0) dfsv(i,num);
  }
  for(i=0;i<num;i++) printf("%d %d %d\n",i+1,found[i],fin[i]);
  
  return 0;
}

void dfsv(int val, int num){
  int i;
  col[val]=1;
  time++;
  found[val]=time;  /*first visit*/
  for(i=0;i<num;i++){
    if(array[val][i]!=1) continue;
    if(col[i]==0) dfsv(i,num);
  }
  col[val]=2;
  time++;
  fin[val]=time; /*finish visit*/
}

