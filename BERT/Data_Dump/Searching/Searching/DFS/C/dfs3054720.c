#include<stdio.h>

void DFS(int,int);

struct Node
{
  int key;
  int discovered_time;
  int finished_time;
};

int time_from_begin = 0;
int List[101][101];
struct Node node[101];

int main()
{
  int n,i,j,key,k;
  
  scanf("%d",&n);
  for(i = 1 ; i<=n ; i++)  for(j = 0 ;j < n ; j++ )  List[i][j] = 0;
  for(i = 1 ; i<= n ; i++)
    {
      node[i].key =0;
      node[i].discovered_time = 0;
      node[i].finished_time = 0;
    }
  for(i = 1; i<= n;i++)
    {
      scanf("%d %d",&node[i].key,&k);
      
      for(j = 0 ; j < k; j++) scanf("%d",&List[node[i].key][j]);//あやしい
    }

  for(i = 1; i <= n ;i++)DFS(i,0);

  for(i = 1 ; i<=n ; i++)printf("%d %d %d\n",i, node[i].discovered_time , node[i].finished_time);
	

      
  

}

void DFS(int node_index ,int List_index)
{
   if(node[node_index].discovered_time ==0)
  {
  time_from_begin++;
  //printf("arrive:node %d time:%d\n",node[node_index].key,time_from_begin);
  if(node[node_index].discovered_time == 0) node[node_index].discovered_time = time_from_begin;
  while(List[node_index][List_index]!=0 && node[node_index].key !=List[node_index][List_index])
    {
      
      DFS( List[node_index][List_index] , 0);
      List_index++;
    }
   time_from_begin++;
  node[node_index].finished_time = time_from_begin;
  
  }
   //printf("left:node %d time:%d\n",node[node_index].key,time_from_begin);
  return;

}

