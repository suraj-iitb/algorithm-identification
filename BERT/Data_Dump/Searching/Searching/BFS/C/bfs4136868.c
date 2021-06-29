#include<stdio.h>
#include<stdlib.h>
void enqueue(int);
int dequeue(void);
int **array,*length,*queue,head,tail,*flag;
int main(){
  int i,j,k,l,n,m;
  scanf("%d",&n);
  array=malloc(sizeof(int*)*(n+1));
  flag=malloc(sizeof(int)*(n+1));
  for(i=0;i<n+1;i++)flag[i]=0;
  //for(i=0;i<n+1;i++)array[i]=malloc(sizeof(int)*(n+1));
  length=malloc(sizeof(int)*(n+1));
  for(i=0;i<n+1;i++)length[i]=-1;
  queue = malloc(sizeof(int)*n);
  //for(i=0;i<n+1;i++)for(j=0;j<n+1;j++)array[i][j]=-1;

  k=n;
  while(k--){
    scanf("%d %d",&i,&l);
    array[i]=malloc(sizeof(int)*(l+1));
    array[i][l]=-1;
    for(j=0;j<l;j++)scanf("%d",&array[i][j]);
  }
  k=1;
  flag[k]=1;
  length[1]=0;
  while(1){
    for(i=0;array[k][i]!=-1;i++){
      if(flag[array[k][i]] == 0){
	flag[array[k][i]]=1;
	length[array[k][i]] = length[k]+1;
	enqueue(array[k][i]);
      }
    }
    k=dequeue();
    if(k == -1)break;
  }

  for(i=1;i<n+1;i++)printf("%d %d\n",i,length[i]);
  
  for(i=0;i<n+1;i++)free(array[i]);
  free(array);
  free(length);
  free(flag);
  free(queue);
  return 0;
}

void enqueue(int n){
  queue[tail++]=n;
}
int dequeue(){
  int num;
  num=queue[head++];
  if(head>tail)return -1;
  return num;
}
  

    
		      

